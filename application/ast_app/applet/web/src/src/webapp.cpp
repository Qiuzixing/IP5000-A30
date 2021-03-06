#include "webapp.h"
#include "debug.h"
#include "Civetweb_API.h"
#include "stringsplit.h"
#include "ast_send_event.h"

#define SUCCESS_CODE                200
#define BAD_REQUEST_CODE            400
#define UNAUTH_CODE                 401
#define WEB_NOT_FOUND               404
#define SERVICE_UNAVAILABLE_CODE    503

#define CAPTURE_BMP_FILE        "/www/capture.bmp"
#define CAPTURE_JPG_FILE        "/www/capture.jpg"
#define MJPEG_TMP_BMP_FILE      "/www/tmp.bmp"
#define MJPEG_TMP_JPG_FILE      "/www/tmp.jpg"


#define UP_CHANNEL_URL          "/upload/channel$"
#define UP_EDID_URL             "/upload/edid$"
#define UP_SLEEPIMAGE_URL       "/upload/sleepimage$"
#define UP_OVERLAY_URL          "/upload/overlayimage$"
#define UP_SECURE_URL           "/upload/secure$"
#define UP_TESTPATTERN_URL      "/upload/testpattern$"
#define UP_UPGRADESOFTWARE      "/upload/upgradesoftware$"
//#define UP_SECURITY           "/upload_security"

#define DOWN_LOGFILE_URL        "/log$"
#define DOWN_CHANNEL_URL        "/channel/channel_map$"
#define DOWN_SECURE_URL         "/secure$"
#define DOWN_TESTPATTERN_URL    "/vw/video_wall_test_pattern$"

// security
#define SECURE_HTTPS_URL        "/security/https$"
#define SECURE_HTTPS_JSON_FILE  "/data/configs/kds-7/secure/https_setting.json"
#define STR_HTTPS_SET           "https_setting"
#define KEY_HTTPS_CERT          "certificate"
#define KEY_HTTPS_MODE          "mode"
#define KEY_HTTPS_METH          "method"
#define KEY_HTTPS_PASSWD        "password"
#define JSON_HTTPS_CERT         "certificate_file_name"
#define JSON_HTTPS_MODE         "mode"
#define JSON_HTTPS_METH         "method"
#define JSON_HTTPS_PASSWD       "private_key_password"
#define SECURE_HTTPS_PATH       "/secure/certificate_file_name"

#define SECURE_802X_URL         "/security/802_1x$"
#define SECURE_802X_JSON_FILE   "/data/configs/kds-7/secure/ieee802_1x_setting.json"
#define STR_802X_SET            "ieee802_1x_setting"
#define STR_802X_EAP_TLS        "eap_tls_setting"
#define STR_802X_MSCHAP_TLS     "eap_mschap_setting"
#define KEY_802X_CA             "tls_ca_certificate"
#define KEY_802X_CLI_PEM        "tls_client_certificate"
#define KEY_802X_CLI_KEY        "tls_private_key"
#define KEY_802X_MODE           "mode"
#define KEY_802X_DEFUT_AUTH     "default_authentication"
#define KEY_802X_USRNAME        "tls_username"
#define KEY_802X_PASSWD         "tls_private_password"
#define KEY_802X_MSCHAP_USER    "mschap_username"
#define KEY_802X_MSCHAP_PASSWD  "mschap_password"
#define CA_802X_PATH            "/secure/tls_ca_certificate"
#define CLI_PEM_802X_PATH       "/secure/tls_client_certificate"
#define CLI_KEY_802X_PATH       "/secure/tls_private_key"


// json????????????
#define JSON_URL                "/device/json$"
#define JSON_PATH_PARAM         "path"
#define DEV_STATUS_URL          "/device/status.json$"

// ???5000??????
#define CMD_TYPE_STR            "cmdtype"
#define CMD_STR_STR             "cmdstr"
#define COMM_CONFIG_STR         "systemconfig"
#define CHANGE_PASSWD_STR       "changepasswd"
#define NEW_PASSWD_STR          "newpasswd"
#define VERIFY_PASSWD_STR       "verifypasswd"
#define PASSWD_STR              "passwd"
#define USRNAME_STR             "username"

#define EXPORT_URL              "/settings/export$"
#define IMPORT_URL              "/settings/import$"
#define LOG_URL                 "/log/log$"

CMutex CWeb::s_p3kmutex;
CCond  CWeb::s_p3kcond;
int CWeb::s_p3kStatus = 0;
struct mg_context * CWeb::ctx = NULL;
int CWeb::s_p3kSocket = -1;

CMutex CWeb::s_HandleMutex;
CMutex CWeb::s_AliveStreamMutex;
CMutex CWeb::s_MjpegUsrCntMutex;
CMutex CWeb::s_MjpegMutex;
CMutex CWeb::s_BmpMutex;
int CWeb::s_KeepAliveWorker = 0;
int CWeb::s_mjpegSeq = 0;
int CWeb::s_mjpegUsrCnt = 0;
int CWeb::s_mjpegEnable = 0;
long long CWeb::s_LastUpdataTime = 0;
int CWeb::s_mjpegIntevalMs = 1000;
int mjpeg_enable = 1;

extern const char *GetModelNumber(void);

#define MAX_READ_BUF_LEN    4096

static  unsigned long crc_table[256] =
{
    0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL, 0x076dc419L,
    0x706af48fL, 0xe963a535L, 0x9e6495a3L, 0x0edb8832L, 0x79dcb8a4L,
    0xe0d5e91eL, 0x97d2d988L, 0x09b64c2bL, 0x7eb17cbdL, 0xe7b82d07L,
    0x90bf1d91L, 0x1db71064L, 0x6ab020f2L, 0xf3b97148L, 0x84be41deL,
    0x1adad47dL, 0x6ddde4ebL, 0xf4d4b551L, 0x83d385c7L, 0x136c9856L,
    0x646ba8c0L, 0xfd62f97aL, 0x8a65c9ecL, 0x14015c4fL, 0x63066cd9L,
    0xfa0f3d63L, 0x8d080df5L, 0x3b6e20c8L, 0x4c69105eL, 0xd56041e4L,
    0xa2677172L, 0x3c03e4d1L, 0x4b04d447L, 0xd20d85fdL, 0xa50ab56bL,
    0x35b5a8faL, 0x42b2986cL, 0xdbbbc9d6L, 0xacbcf940L, 0x32d86ce3L,
    0x45df5c75L, 0xdcd60dcfL, 0xabd13d59L, 0x26d930acL, 0x51de003aL,
    0xc8d75180L, 0xbfd06116L, 0x21b4f4b5L, 0x56b3c423L, 0xcfba9599L,
    0xb8bda50fL, 0x2802b89eL, 0x5f058808L, 0xc60cd9b2L, 0xb10be924L,
    0x2f6f7c87L, 0x58684c11L, 0xc1611dabL, 0xb6662d3dL, 0x76dc4190L,
    0x01db7106L, 0x98d220bcL, 0xefd5102aL, 0x71b18589L, 0x06b6b51fL,
    0x9fbfe4a5L, 0xe8b8d433L, 0x7807c9a2L, 0x0f00f934L, 0x9609a88eL,
    0xe10e9818L, 0x7f6a0dbbL, 0x086d3d2dL, 0x91646c97L, 0xe6635c01L,
    0x6b6b51f4L, 0x1c6c6162L, 0x856530d8L, 0xf262004eL, 0x6c0695edL,
    0x1b01a57bL, 0x8208f4c1L, 0xf50fc457L, 0x65b0d9c6L, 0x12b7e950L,
    0x8bbeb8eaL, 0xfcb9887cL, 0x62dd1ddfL, 0x15da2d49L, 0x8cd37cf3L,
    0xfbd44c65L, 0x4db26158L, 0x3ab551ceL, 0xa3bc0074L, 0xd4bb30e2L,
    0x4adfa541L, 0x3dd895d7L, 0xa4d1c46dL, 0xd3d6f4fbL, 0x4369e96aL,
    0x346ed9fcL, 0xad678846L, 0xda60b8d0L, 0x44042d73L, 0x33031de5L,
    0xaa0a4c5fL, 0xdd0d7cc9L, 0x5005713cL, 0x270241aaL, 0xbe0b1010L,
    0xc90c2086L, 0x5768b525L, 0x206f85b3L, 0xb966d409L, 0xce61e49fL,
    0x5edef90eL, 0x29d9c998L, 0xb0d09822L, 0xc7d7a8b4L, 0x59b33d17L,
    0x2eb40d81L, 0xb7bd5c3bL, 0xc0ba6cadL, 0xedb88320L, 0x9abfb3b6L,
    0x03b6e20cL, 0x74b1d29aL, 0xead54739L, 0x9dd277afL, 0x04db2615L,
    0x73dc1683L, 0xe3630b12L, 0x94643b84L, 0x0d6d6a3eL, 0x7a6a5aa8L,
    0xe40ecf0bL, 0x9309ff9dL, 0x0a00ae27L, 0x7d079eb1L, 0xf00f9344L,
    0x8708a3d2L, 0x1e01f268L, 0x6906c2feL, 0xf762575dL, 0x806567cbL,
    0x196c3671L, 0x6e6b06e7L, 0xfed41b76L, 0x89d32be0L, 0x10da7a5aL,
    0x67dd4accL, 0xf9b9df6fL, 0x8ebeeff9L, 0x17b7be43L, 0x60b08ed5L,
    0xd6d6a3e8L, 0xa1d1937eL, 0x38d8c2c4L, 0x4fdff252L, 0xd1bb67f1L,
    0xa6bc5767L, 0x3fb506ddL, 0x48b2364bL, 0xd80d2bdaL, 0xaf0a1b4cL,
    0x36034af6L, 0x41047a60L, 0xdf60efc3L, 0xa867df55L, 0x316e8eefL,
    0x4669be79L, 0xcb61b38cL, 0xbc66831aL, 0x256fd2a0L, 0x5268e236L,
    0xcc0c7795L, 0xbb0b4703L, 0x220216b9L, 0x5505262fL, 0xc5ba3bbeL,
    0xb2bd0b28L, 0x2bb45a92L, 0x5cb36a04L, 0xc2d7ffa7L, 0xb5d0cf31L,
    0x2cd99e8bL, 0x5bdeae1dL, 0x9b64c2b0L, 0xec63f226L, 0x756aa39cL,
    0x026d930aL, 0x9c0906a9L, 0xeb0e363fL, 0x72076785L, 0x05005713L,
    0x95bf4a82L, 0xe2b87a14L, 0x7bb12baeL, 0x0cb61b38L, 0x92d28e9bL,
    0xe5d5be0dL, 0x7cdcefb7L, 0x0bdbdf21L, 0x86d3d2d4L, 0xf1d4e242L,
    0x68ddb3f8L, 0x1fda836eL, 0x81be16cdL, 0xf6b9265bL, 0x6fb077e1L,
    0x18b74777L, 0x88085ae6L, 0xff0f6a70L, 0x66063bcaL, 0x11010b5cL,
    0x8f659effL, 0xf862ae69L, 0x616bffd3L, 0x166ccf45L, 0xa00ae278L,
    0xd70dd2eeL, 0x4e048354L, 0x3903b3c2L, 0xa7672661L, 0xd06016f7L,
    0x4969474dL, 0x3e6e77dbL, 0xaed16a4aL, 0xd9d65adcL, 0x40df0b66L,
    0x37d83bf0L, 0xa9bcae53L, 0xdebb9ec5L, 0x47b2cf7fL, 0x30b5ffe9L,
    0xbdbdf21cL, 0xcabac28aL, 0x53b39330L, 0x24b4a3a6L, 0xbad03605L,
    0xcdd70693L, 0x54de5729L, 0x23d967bfL, 0xb3667a2eL, 0xc4614ab8L,
    0x5d681b02L, 0x2a6f2b94L, 0xb40bbe37L, 0xc30c8ea1L, 0x5a05df1bL,
    0x2d02ef8dL
};


#define DO1(buf) crc = crc_table[((int)crc ^ (*buf++)) & 0xff] ^ (crc >> 8);
#define DO2(buf)  DO1(buf); DO1(buf);
#define DO4(buf)  DO2(buf); DO2(buf);
#define DO8(buf)  DO4(buf); DO4(buf);
static unsigned long crc32(unsigned long crc, char *buf, unsigned int len)
{
    crc = crc ^ 0xffffffffL;

    while (len >= 8)
    {
        DO8(buf);
        len -= 8;
    }

    if (len) do
        {
            DO1(buf);
        }
        while (--len);

    return crc ^ 0xffffffffL;
}

struct T_PKG_HDR
{
    uint32_t magic_number;   // 0xF0E1D2C3
    uint32_t hdr_len;
    uint32_t customer_id;
    uint32_t product_id;
    uint8_t ver_major;
    uint8_t ver_minor;
    uint8_t ver_revision;
    uint8_t ver_build;
    uint32_t build_time;
    uint32_t data_len;
    uint32_t data_crc;
    uint32_t hdr_crc;
};

#define _UPGRADE_DEBUG_ 1
void dump_hdr_info(struct T_PKG_HDR* pkg_hdr)
{
#if _UPGRADE_DEBUG_
    fprintf(stdout, "package informations as below:\n"
            "====================\n"
            "magic_number = 0x%08x\n"
            "hdr_len = 0x%u\n"
            "customer_id = 0x%08x\n"
            "product_id = 0x%08x\n"
            "ver_major = %u\n"
            "ver_minor = %u\n"
            "ver_revision = %u\n"
            "ver_build = %u\n"
            "build_time = 0x%08x\n"
            "data_len = %u\n"
            "data_crc = 0x%08x\n"
            "hdr_crc = 0x%08x\n"
            "====================\n",
            pkg_hdr->magic_number,
            pkg_hdr->hdr_len,
            pkg_hdr->customer_id,
            pkg_hdr->product_id,
            pkg_hdr->ver_major,
            pkg_hdr->ver_minor,
            pkg_hdr->ver_revision,
            pkg_hdr->ver_build,
            pkg_hdr->build_time,
            pkg_hdr->data_len,
            pkg_hdr->data_crc,
            pkg_hdr->hdr_crc
           );
#endif // _UPGRADE_DEBUG_
}

int extract_bin(const char *in_file_name, const char *out_file_name)
{
    T_PKG_HDR pkg_hdr;
    FILE *fp_s = NULL;
    FILE *fp_t = NULL;
    char buf[MAX_READ_BUF_LEN];

    memset(&pkg_hdr, 0, sizeof(pkg_hdr));
    fp_s = fopen(in_file_name, "rb");

    if (fp_s == NULL)
    {
        printf("can not open input file\n");
        return -1;
    }

    fp_t = fopen(out_file_name, "wb");

    if (fp_t == NULL)
    {
        printf("can not open output file\n");
        return -1;
    }

    int bytes = 0;
    int crc = 0;
    int data_len = 0;
    fseek(fp_s, 0, SEEK_SET);
    bytes = fread(&pkg_hdr, 1, sizeof(pkg_hdr), fp_s);
    dump_hdr_info(&pkg_hdr);

    if (bytes != sizeof(pkg_hdr))
    {
        fprintf(stderr, "ERROR: invalid file.");
        #if _UPGRADE_DEBUG_
        fprintf(stderr, " Read bytes<%d> is not same as pkg_hdr<%d>", bytes, sizeof(pkg_hdr));
        #endif
        fprintf(stderr, "\n");
        return -2;
    }

    if (0xF0E1D2C3 != pkg_hdr.magic_number)
    {
        fprintf(stderr, "ERROR: invalid file.");
        #if _UPGRADE_DEBUG_
        fprintf(stderr, " Wrong magnic <0x%x>", pkg_hdr.magic_number);
        #endif
        fprintf(stderr, "\n");
        return -2;
    }

    if (sizeof(pkg_hdr) != pkg_hdr.hdr_len)
    {
        fprintf(stderr, "ERROR: invalid file.");
        #if _UPGRADE_DEBUG_
        fprintf(stderr, " hdr_len<%d> is not corrrect as <%d>\n", pkg_hdr.hdr_len, sizeof(pkg_hdr));
        #endif
        fprintf(stderr, "\n");
        return -2;
    }

    crc = crc32(0, (char *)(&pkg_hdr), (sizeof(pkg_hdr) - sizeof(pkg_hdr.hdr_crc)));

    if (crc != pkg_hdr.hdr_crc)
    {
        fprintf(stderr, "ERROR: invalid file, sum error\n");
        return -2;
    }

    if (0x0a30 != pkg_hdr.customer_id)
    {
        fprintf(stderr, "ERROR: invalid file.");
        #if _UPGRADE_DEBUG_
        fprintf(stderr, " CID mismatch");
        #endif
        fprintf(stderr, "\n");
        return -2;
    }

    if (0x0a30 != pkg_hdr.customer_id)
    {
        fprintf(stderr, "ERROR: invalid file.");
        #if _UPGRADE_DEBUG_
        fprintf(stderr, " PID mismatch");
        #endif
        fprintf(stderr, "\n");
        return -2;
    }

    const char *product_name[][2] = {
        { "UNKNOWN",     "UNKNOWN"      }, // 0
        { "KDS-EN7",     "KDS-SW3-EN7"  }, // 1
        { "KDS-SW3-EN7", "KDS-EN7"      }, // 2
        { "WP-SW2-EN7",  "WP-SW2-EN7"   }, // 3
        { "KDS-DEC7",    "KDS-DEC7"     }, // 4
        { "WP-DEC7"      "WP-DEC7"      }  // 5
    };
    if (pkg_hdr.product_id > 5)
    {
        fprintf(stderr, "ERROR: invalid file.");
        #if _UPGRADE_DEBUG_
        fprintf(stderr, " PID mismatch");
        #endif
        fprintf(stderr, "\n");
        return -2;
    }
    if (
        (0 != strcasecmp(GetModelNumber(), product_name[pkg_hdr.product_id][0]))
        &&
        (0 != strcasecmp(GetModelNumber(), product_name[pkg_hdr.product_id][1]))
    )
    {
        fprintf(stderr, "ERROR: invalid file.");
        #if _UPGRADE_DEBUG_
        fprintf(stderr, " PID mismatch");
        #endif
        fprintf(stderr, "\n");
        return -2;
    }

    fseek(fp_s, 0, SEEK_END);
    data_len = ftell(fp_s) + 1;
    data_len -= pkg_hdr.hdr_len;

    if (data_len != pkg_hdr.data_len)
    {
        fprintf(stderr, "ERROR: invalid file.");
        #if _UPGRADE_DEBUG_
        fprintf(stderr, " data_len<%d> is not same as pkg_hdr.data_len<%d>", data_len, pkg_hdr.data_len);
        #endif
        fprintf(stderr, "\n");
        return -2;
    }

    fseek(fp_s, sizeof(pkg_hdr), SEEK_SET);
    rewind(fp_t);
    crc = 0;

    do
    {
        memset(buf, 0, sizeof(buf));
        bytes = fread(buf, 1, sizeof(buf), fp_s);

        if (bytes > 0)
        {
            crc = crc32(crc, buf, bytes);
            fwrite(buf, 1, bytes, fp_t);
        }
        else
        {
            break;
        }
    }
    while (1);

    if (pkg_hdr.data_crc != crc)
    {
        fprintf(stderr, "ERROR: invalid file, sum error\n");
        return -2;
    }

    fclose(fp_s);
    fclose(fp_t);
    fprintf(stdout, "extract file done\n");
    return 0;
}

bool CWeb::Start(ConfInfoParam * p_webparam,string Server_mode)
{
	/* Start CivetWeb web server */
	BC_INFO_LOG("server will start with %s",Server_mode.c_str());
	web_options options;
	options.web_allconf_documentroot = p_webparam->web_rootpath;
	options.web_allconf_http_port = p_webparam->web_httpport;
	options.web_allconf_https_port = p_webparam->web_httpsport;
	options.web_httpsconf_cerm = p_webparam->web_cermpath;
	options.web_allconf_thread_num = p_webparam->web_numthread;
	options.web_allconf_enable_keepalive = p_webparam->web_keepaliveenable;
	options.web_allconf_keepalive_timeout = p_webparam->web_keepalivetimems;

	options.web_wsconf_enable_pingpong = p_webparam->web_ws_pingpongenable;
	options.web_wsconf_pingpong_timeout_ms = p_webparam->web_ws_pingpongtimems;

	Server_Start_Mode pStart_Mode;
    if(!Server_mode.empty())
    {
        if(Server_mode == "all")
    	{
    		pStart_Mode = Server_Start_Mode_all;
    	}
    	else if(Server_mode == "https")
    	{
    		pStart_Mode = Server_Start_Mode_Https;
    	}
    	else
    	{
    		pStart_Mode = Server_Start_Mode_Http;
    	}
    }
    else
    {
        if(p_webparam->web_startmode == "both")
        {
            pStart_Mode = Server_Start_Mode_all;
        }
        else if(p_webparam->web_startmode == "https")
        {
            pStart_Mode = Server_Start_Mode_Https;
        }
        else
        {
            pStart_Mode = Server_Start_Mode_Http;
        }
    }

	//pStart_Mode = Server_Start_Mode_all;
	//printf("pStart_Mode = %d\n", pStart_Mode);
	string strCertPaswd  = "";
    if(!COperation::GetCertPasswd(strCertPaswd))
    {
        strCertPaswd = "";
    }
	ctx = ServerStart(&options,pStart_Mode,(void *)strCertPaswd.c_str());
	if(NULL == ctx)
	{
		return false;
	}
	return true;
}

void CWeb::Stop()
{
	ServerStop(ctx);
	ctx = NULL;
}


void CWeb::WebSocketRun(mg_websocket_handler handler,void *cbdata)
{
	SetWebsocketHandler(ctx,handler,cbdata);
}


void CWeb::HttpRun()
{
	/*uri handler list demon*/
	struct uri_list UriHandleList[] =
	{
        {UP_CHANNEL_URL, UploadChannelMapHandle, NULL},
        {DOWN_CHANNEL_URL, DownChannelMapHandle, NULL},
        {"/preview$", ShowSleepImageHandle, NULL}, // ??????
        {UP_SLEEPIMAGE_URL, UpdateSleepImageHandle, NULL},
        {UP_EDID_URL, UpdateEdidHandle, NULL},
        {DOWN_LOGFILE_URL, DownloadLogFileHandle, NULL},
        {UP_OVERLAY_URL, UpdateOverlayImageHandle, NULL},
        {UP_SECURE_URL, UploadSecurHandle, NULL},
        {DOWN_SECURE_URL, DownSecurHandle, NULL},
        {UP_TESTPATTERN_URL, UploadVideoWallHandle, NULL},
        {DOWN_TESTPATTERN_URL, DownVideoWallHandle, NULL},
        {UP_UPGRADESOFTWARE, UploadUpgradeHandle, NULL},
        {JSON_URL, JsonDataHandle, NULL},
        {DEV_STATUS_URL, DeviceStatusHandle, NULL},
        {"/action$", ActionReqHandler, NULL},
        {"/stream$", StreamReqHandler, NULL},
        {"/upload_logo$", UploadLogoReqHandler, NULL},
        {"/upload_bg$", UploadBgReqHandler, NULL},
        {"/capture.bmp$", CapturebmpReqHandler, NULL},
        {"/capture.jpg$", CapturejpgReqHandler, NULL},
        {SECURE_HTTPS_URL, SecureHttpsSetHanndle, NULL},
        {SECURE_802X_URL, Secure802XSetHanndle, NULL},
        {IMPORT_URL, ImportHanndle, NULL},
        {EXPORT_URL, ExportHanndle, NULL},
        {LOG_URL, LogHanndle, NULL},
	};
	AddURIProcessHandler(ctx,UriHandleList,ARRAY_SIZE(UriHandleList));
}

void CWeb::Print_ServerPort()
{
	List_All_ServerPort(ctx);
}

int CWeb::file_found(const char *key,const char *filename,char *path,size_t pathlen,void *user_data)
{
	struct mg_connection *conn = (struct mg_connection *)user_data;
    struct T_FromInfo *pFrom = (struct T_FromInfo *)mg_get_user_connection_data(conn);

	BC_INFO_LOG("the key is %s  the filename is %s",key,filename);
    if (filename && *filename)
    {
        if(strlen(pFrom->filename) == 0 || pFrom->filename == NULL)
        {
	        snprintf(path, pathlen, "%s/%s", pFrom->filepath, filename);
            strncpy(pFrom->filename, filename, strlen(filename));
        }
        else
        {
            snprintf(path, pathlen, "%s/%s", pFrom->filepath, pFrom->filename);
        }
        BC_INFO_LOG("file path is %s",path);
        mg_set_user_connection_data(conn, (void*)pFrom);
	    return MG_FORM_FIELD_STORAGE_STORE;
    }
    return MG_FORM_FIELD_HANDLE_ABORT;
}
int CWeb::file_get(const char *key,const char *value,size_t valuelen,void *user_data)
{
	struct mg_connection *conn = (struct mg_connection *)user_data;
}

int CWeb::file_store(const char *path, long long file_size, void *user_data)
{
	struct mg_connection *conn = (struct mg_connection *)user_data;
    struct T_FromInfo *pFrom = (struct T_FromInfo *)mg_get_user_connection_data(conn);

    pFrom->filesize = file_size;
    BC_INFO_LOG("field_stored path %s  file_size  %lld ", path, pFrom->filesize);

    return 0;
}

bool CWeb::SaveUploadFile(struct mg_connection *conn, const char *i_pPath, const char *i_pFileNmae, struct T_FromInfo *o_tFrominfo)
{
    memset(o_tFrominfo, 0, sizeof(struct T_FromInfo));
    strncpy(o_tFrominfo->filepath, i_pPath, strlen(i_pPath));
    if((i_pFileNmae != NULL) && (strlen(i_pFileNmae) != 0))
    {
        strncpy(o_tFrominfo->filename, i_pFileNmae, strlen(i_pFileNmae));
    }
    mg_set_user_connection_data(conn,(void *)o_tFrominfo);

    struct mg_form_data_handler fdh = {file_found, file_get, file_store, 0};
    fdh.user_data = (void *)conn;

    int ret = Set_Formdata_Handler(conn, &fdh);
    if(ret < 0)
    {
        BC_ERROR_LOG("CWeb::UploadFile Set_Formdata_Handler <%d>", ret);
        return false;
    }

    return true;
}

int CWeb::SecureFileFound(const char *key,const char *filename,char *path,size_t pathlen,void *user_data)
{
    //BC_INFO_LOG("SecureFileFound key is <%s>  the filename is <%s>",key,filename);
    struct mg_connection *conn = (struct mg_connection *)user_data;
    T_SecureInfo *pSecure = (T_SecureInfo *)mg_get_user_connection_data(conn);

    if (filename && *filename)
    {
        if(strncmp(key, KEY_HTTPS_CERT, strlen(KEY_HTTPS_CERT)) == 0)
        {
            pSecure->jsonData[STR_HTTPS_SET][JSON_HTTPS_CERT] = filename;
            snprintf(path, pathlen, "%s%s/%s", DEFAULT_FILE_PATH, SECURE_HTTPS_PATH, filename);
        }
        else if(strncmp(key, KEY_802X_CA, strlen(KEY_802X_CA)) == 0)
        {
            pSecure->jsonData[STR_802X_SET][STR_802X_EAP_TLS][KEY_802X_CA] = filename;
            snprintf(path, pathlen, "%s%s/%s", DEFAULT_FILE_PATH, CA_802X_PATH, filename);
        }
        else if(strncmp(key, KEY_802X_CLI_PEM, strlen(KEY_802X_CLI_PEM)) == 0)
        {
            pSecure->jsonData[STR_802X_SET][STR_802X_EAP_TLS][KEY_802X_CLI_PEM] = filename;
            snprintf(path, pathlen, "%s%s/%s", DEFAULT_FILE_PATH, CLI_PEM_802X_PATH, filename);
        }
        else if(strncmp(key, KEY_802X_CLI_KEY, strlen(KEY_802X_CLI_KEY)) == 0)
        {
            pSecure->jsonData[STR_802X_SET][STR_802X_EAP_TLS][KEY_802X_CLI_KEY] = filename;
            snprintf(path, pathlen, "%s%s/%s", DEFAULT_FILE_PATH, CLI_KEY_802X_PATH, filename);
        }
        BC_INFO_LOG("SecureFileFound file path is <%s>", path);
        mg_set_user_connection_data(conn, (void*)pSecure);

        return MG_FORM_FIELD_STORAGE_STORE;
    }

    return MG_FORM_FIELD_STORAGE_GET;
}

int CWeb::SecureFileGet(const char *key,const char *value,size_t valuelen,void *user_data)
{
	struct mg_connection *conn = (struct mg_connection *)user_data;
    T_SecureInfo *pSecure = (T_SecureInfo *)mg_get_user_connection_data(conn);

    string strValue(value, valuelen);
    BC_INFO_LOG("SecureFileGet key is <%s> value is <%s>", key, strValue.c_str());
    if(pSecure->strSecureFile == SECURE_HTTPS_JSON_FILE)
    {
        string strTmp;
        if(strncmp(key, KEY_HTTPS_MODE, strlen(KEY_HTTPS_MODE)) == 0)
        {
            strTmp = JSON_HTTPS_MODE;
        }
        else if(strncmp(key, KEY_HTTPS_METH, strlen(KEY_HTTPS_METH)) == 0)
        {
            strTmp = JSON_HTTPS_METH;
        }
        else if(strncmp(key, KEY_HTTPS_PASSWD, strlen(KEY_HTTPS_PASSWD)) == 0)
        {
            strTmp = JSON_HTTPS_PASSWD;
        }
        pSecure->jsonData[STR_HTTPS_SET][strTmp.c_str()] = strValue.c_str();
    }
    else if(pSecure->strSecureFile == SECURE_802X_JSON_FILE)
    {
        if(strncmp(key, KEY_802X_MODE, strlen(KEY_802X_MODE)) == 0
          || strncmp(key, KEY_802X_DEFUT_AUTH, strlen(KEY_802X_DEFUT_AUTH)) == 0)
        {
            pSecure->jsonData[STR_802X_SET][key] = strValue.c_str();
        }
        else if(strncmp(key, "mschap", strlen("mschap")) == 0)
        {
            pSecure->jsonData[STR_802X_SET][STR_802X_MSCHAP_TLS][key] = strValue.c_str();
        }
        else
        {
            pSecure->jsonData[STR_802X_SET][STR_802X_EAP_TLS][key] = strValue.c_str();
        }
    }
    mg_set_user_connection_data(conn, (void*)pSecure);
}

int CWeb::SecureFileGetStore(const char *path, long long file_size, void *user_data)
{
	My_System("sync");
    BC_INFO_LOG("field_stored path %s  file_size  %lld ", path, file_size);

    return 0;
}

bool CWeb::SaveSecureFile(struct mg_connection *conn, const char *i_pJsonFile, T_SecureInfo *o_tInfo)
{
    string strConfigInfo = "";
    o_tInfo->strSecureFile = i_pJsonFile;
    if(COperation::GetJsonFile(i_pJsonFile, strConfigInfo))
    {
        Json::Reader reader;
        if(!reader.parse(strConfigInfo, o_tInfo->jsonData))
        {
           BC_INFO_LOG("JsonDataHandle POST json parse failed");
           send_http_error_rsp(conn);
           return false;
        }
    }
    mg_set_user_connection_data(conn,(void *)o_tInfo);

    struct mg_form_data_handler fdh = {SecureFileFound, SecureFileGet, SecureFileGetStore, 0};
    fdh.user_data = (void *)conn;

    int ret = Set_Formdata_Handler(conn, &fdh);
    if(ret < 0)
    {
        BC_ERROR_LOG("CWeb::SaveSecureFile result <%d>", ret);
        return false;
    }

    return true;
}

int CWeb::SecureHttpsSetHanndle(struct mg_connection *conn, void *cbdata)
{
    bool bRes = false;
    string strFile = DEFAULT_FILE_PATH;
    strFile += SECURE_HTTPS_PATH;
    strFile += "/";
    T_SecureInfo tHttpsInfo;

    do
    {
        if(!SaveSecureFile(conn, SECURE_HTTPS_JSON_FILE, &tHttpsInfo))
        {
            BC_INFO_LOG("SecureHttpsSetHanndle upload file error");
            break;
        }

        if(tHttpsInfo.jsonData[STR_HTTPS_SET][JSON_HTTPS_CERT].empty())
        {
            break;
        }

        strFile += tHttpsInfo.jsonData[STR_HTTPS_SET][JSON_HTTPS_CERT].asCString();
        if(!COperation::CheckCertFile(strFile.c_str(), tHttpsInfo.jsonData[STR_HTTPS_SET][JSON_HTTPS_PASSWD].asCString()))
        {
            BC_INFO_LOG("SecureHttpsSetHanndle caheck cert error");
            ::remove(strFile.c_str());
            break;
        }

        // https????????????
        string strHttps = "http";
        if(tHttpsInfo.jsonData[STR_HTTPS_SET][JSON_HTTPS_MODE].asString() == "on")
        {
            strHttps = "https";
        }

        if(!COperation::SetWebSecurityMode(strHttps.c_str()))
        {
            BC_INFO_LOG("SetWebSecurityMode failed!");
            break;
        }

        if(!COperation::SetCertificate(strFile.c_str()))
        {
            BC_INFO_LOG("SetCertificate failed!");
            break;
        }

        Json::FastWriter fastwiter;
        string strConfInfo = "";
        strConfInfo = fastwiter.write(tHttpsInfo.jsonData);
        if(!COperation::SetJsonFile(strConfInfo.c_str(), SECURE_HTTPS_JSON_FILE))
        {
            break;
        }

        BC_INFO_LOG("SecureHttpsSetHanndle upload file OK");
        bRes = true;
    }while(0);

    if(bRes)
    {
        send_http_ok_rsp(conn);

        // reboot
        if(My_System("reboot") < 0)
        {
            BC_INFO_LOG("SecureHttpsSetHanndle reboot failed!");
        }
    }
    else
    {
        string strResInfo = "";
        Json::Value root;
        root["result"] = "Invalid File";
        Json::FastWriter fastwiter;
        strResInfo = fastwiter.write(root);

        mg_send_status(conn, 406);
        mg_printf(conn, "%s",
								"Cache-Control: no-cache\r\n"
								"Connection: close\r\n"
								"Content-Type: application/json;charset=utf-8\r\n\r\n");
	    mg_printf(conn,"%s", strResInfo.c_str());
    }

    return 1;
}

int CWeb::Secure802XSetHanndle(struct mg_connection *conn, void *cbdata)
{
    T_SecureInfo t802XInfo;

    if(SaveSecureFile(conn, SECURE_802X_JSON_FILE, &t802XInfo))
    {
        Json::FastWriter fastwiter;
        string strConfInfo = "";
        strConfInfo = fastwiter.write(t802XInfo.jsonData);
        if(!COperation::SetJsonFile(strConfInfo.c_str(), SECURE_802X_JSON_FILE))
        {
            send_http_error_rsp(conn);
            return 1;
        }

        BC_INFO_LOG("Secure802XSetHanndle upload file OK");
        ast_send_event(0xFFFFFFFF,"e_802_1x");
        send_http_ok_rsp(conn);
    }
    else
    {
        BC_INFO_LOG("Secure802XSetHanndle upload file error");
        send_http_error_rsp(conn);
    }

    return 1;
}

// ????????????
int CWeb::UploadChannelMapHandle(struct mg_connection *conn, void *cbdata)
{
    struct T_FromInfo tFrom;
    if(!SaveUploadFile(conn, DEFAULT_FILE_PATH "/channel", "channel_map.json", &tFrom))
    {
        BC_INFO_LOG("TransmitChannelMapHandle upload file error");
    }
    else
    {
        BC_INFO_LOG("TransmitChannelMapHandle upload file OK");
        send_http_ok_rsp(conn);
        return 1;
    }
    send_http_error_rsp(conn);

    return 1;
}

int CWeb::DownChannelMapHandle(struct mg_connection *conn, void *cbdata)
{
    const struct mg_request_info *pRequest = mg_get_request_info(conn);

    if(strcmp(pRequest->request_method, "GET") == 0)
    {
        send_chunk_file(conn, CHANNEL_FILE_PATH, "channel_map.json");
    }
    else
    {
        send_http_error_rsp(conn);
    }

    return 1;
}

int CWeb::ShowSleepImageHandle(struct mg_connection *conn, void *cbdata)
{
    string strFile = DEFAULT_FILE_PATH;
    strFile += SLEEPIMAGE_FILE_PATH;

    mg_send_file(conn, strFile.c_str());
    return 1;
}

int CWeb::UpdateSleepImageHandle(struct mg_connection *conn, void *cbdata)
{
    struct T_FromInfo tFrom;
    if(!SaveUploadFile(conn, DEFAULT_FILE_PATH "/display", "sleep_image.jpg", &tFrom))
    {
        BC_INFO_LOG("UpdateSleepImageHandle upload file error");
        send_http_error_rsp(conn);
    }
    else
    {
        BC_INFO_LOG("UpdateSleepImageHandle upload file OK");
        My_System("e e_update_idle_screen");
        send_http_ok_rsp(conn);
    }

    return 1;
}

int CWeb::UpdateEdidHandle(struct mg_connection *conn, void *cbdata)
{
#if 0
    struct T_FromInfo tFrom;
    if(!SaveUploadFile(conn, "/tmp", NULL, &tFrom))
    {
        BC_INFO_LOG("UpdateEdidHandle upload file error");
    }
    else
    {
        char aTmpName[MAX_KEY_VALUE_SIZE] = {0};
        sprintf(aTmpName, "%s/%s", tFrom.filepath, tFrom.filename);

        if(COperation::UpdateEdidFile(aTmpName))
        {
            send_http_ok_rsp(conn);
            return 1;
        }
    }
    send_http_error_rsp(conn);
#endif

    bool bRes = false;
    struct T_FromInfo tFrom;
    Json::Value root;
    root["result"] = "File corrupted";

    Json::FastWriter fastwiter;
    string strConfInfo = "";
    strConfInfo = fastwiter.write(root);

    if(SaveUploadFile(conn, "/tmp", NULL, &tFrom))
    {
        string strTmpFile = tFrom.filepath;
        strTmpFile += "/";
        strTmpFile += tFrom.filename;
        BC_INFO_LOG("edid file is [%s]", strTmpFile.c_str());
        if(COperation::CheckEdidFile(strTmpFile.c_str()))
        {
            bRes = true;
        }
        else
        {
            bRes = false;
        }
    }


    if(bRes)
    {
        BC_INFO_LOG("UpdateEdidHandle upload file OK");
        send_http_ok_rsp(conn);
    }
    else
    {
        mg_send_status(conn, BAD_REQUEST_CODE);
        mg_printf(conn, "%s",
								"Cache-Control: no-cache\r\n"
								"Connection: close\r\n"
								"Content-Type: application/json;charset=utf-8\r\n\r\n");
        mg_printf(conn, "%s", strConfInfo.c_str());
    }

    return 1;
}

int CWeb::DownloadLogFileHandle(struct mg_connection *conn, void *cbdata)
{
    send_chunk_file(conn, "/log/log_file.txt", "log_file.txt");

    return 1;
}

int CWeb::UpdateOverlayImageHandle(struct mg_connection *conn, void *cbdata)
{
    CMutexLocker locker(&s_HandleMutex);
    // clean old overlay image
    char szCmd[MAX_CMD_STR] = {0};
    snprintf(szCmd, sizeof(szCmd)-1, "rm -f %s/*.png", OVERLAY_FILE_PATH);
    if(My_System(szCmd) < 0)
    {
        BC_ERROR_LOG("remove overlay image clear failed!!");
    }

    struct T_FromInfo tFrom;
    if(SaveUploadFile(conn, OVERLAY_FILE_PATH, NULL, &tFrom))
    {
        string strConfigInfo = "";
        if(COperation::GetJsonFile(OVERLAY_JSON_FILE, strConfigInfo))
        {
            Json::Value json;
            Json::Reader reader;
            if(!reader.parse(strConfigInfo, json))
            {
               BC_INFO_LOG("JsonDataHandle POST json parse failed");
               send_http_error_rsp(conn);
               return 1;
            }

            string strFile = OVERLAY_FILE_PATH;
            strFile += "/";
            strFile += tFrom.filename;

            for(int i = 0; i < json["objects"].size(); i++)
            {
                if(!json["objects"][i]["path"].empty())
                {
                    json["objects"][i]["path"] = strFile.c_str();
                }
            }

            Json::FastWriter fastwiter;
            string strTmp = "";
            strTmp = fastwiter.write(json);
            if(COperation::SetJsonFile(strTmp.c_str(), OVERLAY_JSON_FILE))
            {
                send_http_ok_rsp(conn);
                return 1;
            }
        }
    }

    BC_INFO_LOG("UpdateOverlayImageHandle failed");
    send_http_error_rsp(conn);

    return 1;
}


/*
int CWeb::TransmitPresetsFileHandle(struct mg_connection *conn, void *cbdata)
{
    // ??????????????????
    const struct mg_request_info *pRequest = mg_get_request_info(conn);
    if(strcmp(pRequest->request_method, "GET") == 0)
    {
        mg_send_file(conn, "/opt/configs/kds-n-6X/usr/etc/presets/preset1.json");

        return 1;
    }

    if(strcmp(pRequest->request_method, "POST") == 0)
    {
        struct mg_form_data_handler fdh = {file_found, file_get, file_store, 0};
        fdh.user_data = (void *)conn;

        int ret = Set_Formdata_Handler(conn, &fdh);
        if(ret < 0)
        {
            BC_ERROR_LOG("CWeb::TransmitPresetsFileHandle Set_Formdata_Handler <%d>", ret);
        }

        // ???????????????????????????
        string strFileName = (char *)mg_get_user_connection_data(conn);

        // ??????????????????????????????????????????(??????)

        // ??????????????????
        send_http_ok_rsp(conn);

        return 1;
    }

    send_http_error_rsp(conn);

    return 1;
}
*/

int CWeb::UploadSecurHandle(struct mg_connection *conn, void *cbdata)
{
    struct T_FromInfo tFrom;
    if(!SaveUploadFile(conn, DEFAULT_FILE_PATH "/secure", NULL, &tFrom))
    {
        BC_INFO_LOG("TransmitSecurHandle upload file error");
        send_http_error_rsp(conn);
    }
    else
    {
        BC_INFO_LOG("TransmitSecurHandle upload file OK");
        send_http_ok_rsp(conn);
    }

    return 1;
}

int CWeb::DownSecurHandle(struct mg_connection *conn, void *cbdata)
{
    send_chunk_file(conn, "/secure/server.pem", "server.pem");

    return 1;
}

int CWeb::UploadVideoWallHandle(struct mg_connection *conn, void *cbdata)
{
    struct T_FromInfo tFrom;
    if(!SaveUploadFile(conn, DEFAULT_FILE_PATH "/vw", "video_wall_test_pattern.png", &tFrom))
    {
        BC_INFO_LOG("TransmitVideoWallHandle upload file error");
        send_http_error_rsp(conn);
    }
    else
    {
        BC_INFO_LOG("TransmitVideoWallHandle upload file OK");
        send_http_ok_rsp(conn);
    }

    return 1;
}

int CWeb::DownVideoWallHandle(struct mg_connection *conn, void *cbdata)
{
    send_chunk_file(conn, DEFAULT_FILE_PATH "/vw/video_wall_test_pattern.png", "video_wall_test_pattern.png");

    return 1;
}

int CWeb::UploadUpgradeHandle(struct mg_connection *conn, void *cbdata)
{
    struct T_FromInfo tFrom;
    mjpeg_enable = 0;
    int err = 0;
    if(!SaveUploadFile(conn, UPGRADE_FILE_PATH, "fw.bin", &tFrom))
    {
        BC_INFO_LOG("UploadUpgradeHandle upload file error");
        send_http_error_rsp(conn);
    }
    else
    {
        BC_INFO_LOG("UploadUpgradeHandle upload file OK");
        err = extract_bin(UPGRADE_FILE_PATH "/fw.bin", UPGRADE_FILE_PATH "/fw.tar.gz");
        switch (err)
        {
            case 0:
                send_http_ok_rsp(conn);
                break;
            case -2:
                (void)remove(UPGRADE_FILE_PATH"/fw.bin");
                BC_INFO_LOG("extract_bin failed");
                send_http_usererror_body_rsp(conn, 406, "{ \"result\": \"Invalid File\" }");
                break;
            case -1:
                (void)remove(UPGRADE_FILE_PATH"/fw.bin");
                BC_INFO_LOG("extract_bin failed, but it is a internal error");
                send_http_usererror_rsp(conn, 500);
            default:
                break;
        }
    }
    mjpeg_enable = 1;
    return 1;
}

int CWeb::JsonDataHandle(struct mg_connection *conn, void *cbdata)
{
    CMutexLocker locker(&s_HandleMutex);
    const struct mg_request_info *pRequest = mg_get_request_info(conn);
    //BC_INFO_LOG("content data len is [%lld]", pRequest->content_length);

    if(strcmp(pRequest->request_method, "GET") == 0)
    {
        bool bHandleReq = false;
        string strConfigInfo = "";
        string strFile = DEFAULT_FILE_PATH;
        char szPath[MAX_PARAM_LEN] = {0};
        mg_get_var_from_querystring(conn, "path", szPath, MAX_PARAM_LEN);

        strFile += szPath;
        if(COperation::GetJsonFile(strFile.c_str(), strConfigInfo))
        {
            bHandleReq = true;
            BC_INFO_LOG("json ConfigInfo is <%s>", strConfigInfo.c_str());
            BC_mg_send_header(conn, "Content-Type", "application/json");
            mg_printf_data(conn, true, "%s", strConfigInfo.c_str());
            mg_printf(conn, "%x\r\n\r\n", 0x00);
        }

        if(!bHandleReq)
        {
            send_http_error_rsp(conn);
        }
    }

    if(strcmp(pRequest->request_method, "POST") == 0)
    {
        size_t sLen = 0;
        bool bHandleReq = false;
        string strP3kConfCmd = "#KDS-CFG-MODIFY ";
        char szContent[pRequest->content_length + 1];
        memset(szContent, 0, pRequest->content_length + 1);
        string strFile = DEFAULT_FILE_PATH;

        sLen = BC_GET_Request_Body(conn, szContent, (pRequest->content_length));
        BC_INFO_LOG("get request body is <%s>", szContent);

        // ??????json??????
        Json::Value json;
        Json::Reader reader;
        string strJsonInfo = szContent;
        if(!reader.parse(strJsonInfo, json))
        {
           BC_INFO_LOG("JsonDataHandle POST json parse failed");
           send_http_error_rsp(conn);
           return 1;
        }

        string strPath = json["path"].asString();
        strFile += strPath;
        strP3kConfCmd += strPath;
        strP3kConfCmd += "\r";

        // overlay2_setting.json ????????????
        if(strFile == OVERLAY_JSON_FILE)
        {
            string strOverlayInfo = "";
            if(COperation::GetJsonFile(OVERLAY_JSON_FILE, strOverlayInfo))
            {
                Json::Value jsonOverlay;
                Json::Reader readOverlay;
                if(!reader.parse(strOverlayInfo, jsonOverlay))
                {
                   BC_INFO_LOG("overlay2_setting json parse failed");
                   send_http_error_rsp(conn);
                   return 1;
                }

                if(jsonOverlay["objects"].size() < 1)
                {
                    BC_ERROR_LOG("overlay2_setting objects size is 0");
                    send_http_error_rsp(conn);
                    return 1;
                }

                string strOverFile = jsonOverlay["objects"][0]["path"].asString();

                int i = 0;
                for(i; i < json["info"]["objects"].size(); i++)
                {
                    json["info"]["objects"][i]["path"] = strOverFile.c_str();
                }
            }
            else
            {
                send_http_error_rsp(conn);
                return 1;
            }
        }

        Json::FastWriter fastwiter;
        string strConfInfo = "";
        strConfInfo = fastwiter.write(json["info"]);


        if(COperation::SetJsonFile(strConfInfo.c_str(), strFile.c_str()))
        {
            bHandleReq = true;
            send_http_ok_rsp(conn);
        }

        if(!bHandleReq)
        {
            send_http_error_rsp(conn);
        }
        else
        {
            CMutexLocker locker(&s_p3kmutex);
            if((s_p3kSocket < 0)
                || (s_p3kStatus != 1))
            {
                BC_INFO_LOG("p3k socket error");
                return 1;
            }
            int maxfd;
        	fd_set Writefds;
        	maxfd = s_p3kSocket + 1;
        	FD_ZERO(&Writefds);
        	FD_SET(s_p3kSocket, &Writefds);

        	int nret = select(maxfd, NULL, &Writefds, NULL, NULL);
        	if(nret < 0)
        	{
        		BC_INFO_LOG("json select failed");
        	}

            if(nret > 0)
            {
                if(FD_ISSET(s_p3kSocket,&Writefds))
                {
                    int WriteSize = write(s_p3kSocket, strP3kConfCmd.c_str(), strP3kConfCmd.length());
                    if(WriteSize < 0)
                    {
                        BC_INFO_LOG("json p3k write failed");
                    }

                    // ??????
                    usleep(1000);
                }
            }
        }
    }

    return 1;
}

int CWeb::DeviceStatusHandle(struct mg_connection *conn, void *cbdata)
{
    FILE *fp = NULL;
    char szResData[1024] = {0};

    fp = popen("cat /proc/uptime", "r");
    if(fp != NULL)
    {
        if(fgets(szResData, sizeof(szResData), fp) == NULL)
        {
            BC_INFO_LOG("DeviceStatusHandle fgets failed!");
            send_http_error_rsp(conn);

            fclose(fp);
            return 1;
        }
        BC_INFO_LOG("DeviceStatusHandle get data is [%s]", szResData);

        string strResult = "";
        string strFileData = szResData;
        int nsite = strFileData.find(" ");
        string strTmp = strFileData.substr(0, nsite);

        Json::Value json;
        Json::Value devstatus;
        Json::FastWriter fastwiter;

        devstatus["uptime"] = strTmp.c_str();
        json["device_status"] = devstatus;

        strResult = fastwiter.write(json);
        send_json_data(conn, (char *)strResult.c_str());
    }
    else
    {
        BC_INFO_LOG("DeviceStatusHandle get data failed!");
        send_http_error_rsp(conn);
    }

    fclose(fp);
    return 1;
}

int CWeb::ActionReqHandler(struct mg_connection *conn, void *cbdata)
{
    bool bHandleReq = false;
    char szCmdType[MAX_PARAM_LEN] = {0};
    char szCmdStr[MAX_PARAM_LEN] = {0};

    mg_get_var_from_querystring(conn, CMD_TYPE_STR, szCmdType, MAX_PARAM_LEN);
    mg_get_var_from_querystring(conn, CMD_STR_STR, szCmdStr, MAX_PARAM_LEN);
    BC_INFO_LOG("CMD_TYPE_STR is <%s>  CMD_STR_STR is <%s>", szCmdType, szCmdStr);

    if(0 == ::strncasecmp(szCmdType, COMM_CONFIG_STR, strlen(COMM_CONFIG_STR)))
    {
        if (0 == ::strncasecmp(szCmdStr, CHANGE_PASSWD_STR, strlen(CHANGE_PASSWD_STR)))
        {
            bHandleReq = true;
            char szNewPasswd[MAX_PARAM_LEN] = {0};

            int len = mg_get_var_from_querystring(conn, NEW_PASSWD_STR, szNewPasswd, MAX_PARAM_LEN);
            if (len > 0)
			{
			    if(COperation::SetPassword(szNewPasswd))
                {
                    mg_send_status(conn, SUCCESS_CODE);
                }
                else
                {
                    mg_send_status(conn, SERVICE_UNAVAILABLE_CODE);
                }
            }
            else
            {
                mg_send_status(conn, SERVICE_UNAVAILABLE_CODE);
            }
        }
        else if(0 == ::strncasecmp(szCmdStr, VERIFY_PASSWD_STR, strlen(VERIFY_PASSWD_STR)))
        {
            bHandleReq = true;
            char szUserName[MAX_PARAM_LEN] = {0};
            char szPasswd[MAX_PARAM_LEN] = {0};

            mg_get_var_from_querystring(conn, PASSWD_STR, szPasswd, MAX_PARAM_LEN);
            mg_get_var_from_querystring(conn, USRNAME_STR, szUserName, MAX_PARAM_LEN);
            BC_INFO_LOG("username : %s  passwd : %s",szUserName,szPasswd);

            if(COperation::VerifyPassword(szUserName, szPasswd))
            {
                mg_send_status(conn, SUCCESS_CODE);
            }
            else
            {
                mg_send_status(conn, SERVICE_UNAVAILABLE_CODE);
            }
        }
    }

    if(!bHandleReq)
    {
        mg_send_status(conn, BAD_REQUEST_CODE);
    }

    char szCnt[512] = {0};
    snprintf(szCnt, sizeof(szCnt)-1, "Content-Type: text/plain\r\n"
            "Connection: close\r\n");
    mg_write(conn, szCnt, strlen(szCnt));
    mg_printf(conn, "\r\n");
    mg_printf(conn, "\r\n");

    return 1;
}

conn_state* CWeb::get_state(struct mg_connection * conn)
{
	const struct mg_request_info * ri = mg_get_request_info(conn);
    const char * uri = ri->request_uri;
    //state = (struct conn_state *)conn->request_info.conn_data;
    struct conn_state *state = (struct conn_state *)mg_get_user_connection_data(conn);
    if (NULL == state)
    {
        if (NULL == uri)
        {
        	printf("uri is NULL\n");
            return NULL;
        }
        state = (struct conn_state *)malloc(sizeof(struct conn_state));
        if (strncmp(uri, "/action", 7) == 0 && (uri[7] == '\0' || uri[7] == '?'))
        {
            state->request_type = request_fast_cgi;
        }
        else if (strncmp(uri, "/stream", 7) == 0 && (uri[7] == '\0' || uri[7] == '?') && s_mjpegEnable)
        {
            state->request_type = request_mjpeg;
        }
        else if (strncmp(uri, "/upload_logo", 12) == 0 && (uri[12] == '\0' || uri[12] == '?'))
        {
            state->request_type = request_upload_logo;
        }
        else if (strncmp(uri, "/upload_bg", 10) == 0 && (uri[10] == '\0' || uri[10] == '?'))
        {
            state->request_type = request_upload_bg_pic;
        }
        else if (strncmp(uri, "/capture.bmp", 12) == 0 && (uri[12] == '\0' || uri[12] == '?') && s_mjpegEnable)
        {
            state->request_type = request_dl_bmp;
        }
        else if (strncmp(uri, "/capture.jpg", 12) == 0 && (uri[12] == '\0' || uri[12] == '?') && s_mjpegEnable)
        {
            state->request_type = request_dl_jpg;
        }
        else
        {
            state->request_type = request_default;
        }
        state->fp = NULL;
        state->last_poll = 0;
        state->var[0] = '\0';
        state->boundary[0] = '\0';
        state->flen = 0;
        state->last_mjpeg_seq = s_mjpegSeq;
        mg_set_user_connection_data(conn, state);
        BC_INFO_LOG("conn_state : request_type : %d ; last_mjpeg_seq : %d \n",state->request_type,state->last_mjpeg_seq);
    }
    return state;
}


int CWeb::StreamReqHandler(struct mg_connection *conn, void *cbdata)
{
    const struct mg_request_info *ri = mg_get_request_info(conn);
	struct conn_state *state = get_state(conn);

    if(s_KeepAliveWorker <= 5)
    {
        if (0 == state->last_poll)
	    {
	        s_mjpegUsrCnt++;//????????
	    }
		state->last_poll = ::time(NULL);
    }

    int mjpeg_seq_last = s_mjpegSeq;
    {
        CMutexLocker locker(&s_AliveStreamMutex);
        s_KeepAliveWorker++;
        BC_INFO_LOG("s_KeepAliveWorker : <%d>  s_mjpegUsrCnt : <%d>\n",s_KeepAliveWorker,s_mjpegUsrCnt);
    }

    int result;
	int the_first_conn = 0;
    if(s_KeepAliveWorker <= 5)
	{
		while(1)
		{
		    if(mjpeg_seq_last != s_mjpegSeq)
            {
                if(0 == the_first_conn)
				{
					mg_printf(conn, "%s",
								"HTTP/1.1 200 OK\r\n" "Cache-Control: no-cache\r\n"
								"Pragma: no-cache\r\nExpires: Thu, 01 Dec 1994 16:00:00 GMT\r\n"
								"Connection: close\r\nContent-Type: multipart/x-mixed-replace; "
								"boundary=--w00t\r\n\r\n");
					the_first_conn++;
				}

                int n;
                int result = 0;
                FILE *fp = NULL;
                char buf[640 * 1024];
                struct stat st;
                s_BmpMutex.Lock();
                if (stat(MJPEG_TMP_JPG_FILE, &st) == 0 && (fp = fopen(MJPEG_TMP_JPG_FILE, "rb")) != NULL)
                {
                    s_MjpegMutex.Lock();
                    mg_printf(conn, "--w00t\r\nContent-Type: image/jpeg\r\n"
                            "Content-Length: %lu\r\n\r\n", (unsigned long) st.st_size);
                    while ((n = fread(buf, 1, sizeof(buf), fp)) > 0)
                    {
                        int write_ret = mg_write(conn, buf, n);
                        if(write_ret <= 0)
                        {
                            result = 1;
            				break;
                        }
                        //usleep(100);
                    }
                    fclose(fp);
                    mg_write(conn, "\r\n", 2);
                    s_MjpegMutex.Unlock();
                }
                s_BmpMutex.Unlock();

                if(result != 0)
                {
                    BC_INFO_LOG("send fail ! \n");
                    break;
                }
                mjpeg_seq_last = s_mjpegSeq;
            }
            ::sleep(1);
        }
    }

    {
        CMutexLocker locker(&s_MjpegUsrCntMutex);
        if(s_mjpegUsrCnt > 0)
        {
            s_mjpegUsrCnt--;
        }
    }

    {
        CMutexLocker locker(&s_AliveStreamMutex);
        if(s_KeepAliveWorker > 0)
        {
            s_KeepAliveWorker--;
        }
    }

    if (NULL != state->fp)
	{
		fclose(state->fp);
		state->fp = NULL;
	}
	free(state);
	state = NULL;

    mg_set_user_connection_data(conn,NULL);

    return 1;
}

int CWeb::UploadLogoReqHandler(struct mg_connection *conn, void *cbdata)
{
    struct T_FromInfo tFrom;
    bool bRet = SaveUploadFile(conn, "/dev/shm", "logo.bmp", &tFrom);
    if(!bRet)
    {
        mg_printf(conn,"%s","HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n");
        mg_write(conn, "\r\n", 2);
        mg_printf(conn, "Had no data to write...");
    }
    else
    {
        mg_printf(conn,"%s","HTTP/1.1 200 OK\r\n");
        mg_write(conn, "\r\n", 2);

        mg_printf(conn,
        				"<html>\r\n"
                    "<head>\r\n"
                    "<title></title>\r\n"
                    "<script type=\"text/javascript\" src=\"ajax_obj.js\"></script>\r\n"
                    "</head>\r\n"
                    "<body>\r\n"
                    "<div>\r\n"
                    "<form action=\"upload_logo\" enctype=\"multipart/form-data\" method=\"post\">\r\n"
                    "<p>\r\n"
                    "<input type=\"file\" name=\"logo.bmp\">\r\n"
                    "</p>\r\n"
                    "<p>\r\n"
                    "<input type=\"submit\" value=\"Upload\">\r\n"
                    "</p>\r\n");
        if(tFrom.filesize > 128 * 1024)
        {
            mg_printf(conn,
						"<p style=\"color:red\">Failed!</p>\r\n"
						"<p>Upload %lld bytes</p>\r\n"
						"<p>The picture is larger than %d bytes</p>\r\n"
						"</form>"
						 "</div>"
	                    "</body>"
	                    "</html>",tFrom.filesize, 128 * 1024);
		    mg_send_status(conn, BAD_REQUEST_CODE);
        }
        else
        {
            My_System("dd if=/dev/shm/logo.bmp of=/dev/mtdblklogo bs=64k");
            remove("/dev/shm/logo.bmp");

            mg_printf(conn,
						"<p style=\"color:green\">OK!</p>\r\n"
						"<p>Upload %lld bytes</p>\r\n"
						"</form>"
						 "</div>"
	                    "</body>"
	                    "</html>",tFrom.filesize);
        }
    }

    return 1;
}

int CWeb::UploadBgReqHandler(struct mg_connection *conn, void *cbdata)
{
    struct T_FromInfo tFrom;
    bool bRet = SaveUploadFile(conn, "/dev/shm", "default.jpg", &tFrom);
    if(!bRet)
    {
        mg_printf(conn,"%s","HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n");
        mg_write(conn, "\r\n", 2);
        mg_printf(conn, "Had no data to write...");
    }
    else
    {
        mg_printf(conn,"%s","HTTP/1.1 200 OK\r\n");
        mg_write(conn, "\r\n", 2);
        mg_printf(conn,
        				"<html>\r\n"
		                "<head>\r\n"
		                "<title></title>\r\n"
		                "<script type=\"text/javascript\" src=\"ajax_obj.js\"></script>\r\n"
		                "</head>\r\n"
		                "<body>\r\n"
		                "<div>\r\n"
		                "<form action=\"upload_bg\" enctype=\"multipart/form-data\" method=\"post\">\r\n"
		                "<p>\r\n"
		                "<input type=\"file\" name=\"bg.jpg\">\r\n"
		                "</p>\r\n"
		                "<p>\r\n"
		                "<input type=\"submit\" value=\"Upload\">\r\n"
		                "</p>\r\n");

        if (tFrom.filesize > (1024 + 512) * 1024)
        {
            mg_printf(conn,
						"<p style=\"color:red\">Failed!</p>\r\n"
						"<p>Upload %lld bytes</p>\r\n"
						"<p>The picture is larger than %d bytes</p>\r\n"
						"</form>"
						 "</div>"
	                    "</body>"
	                    "</html>",tFrom.filesize, (1024 + 512) * 1024);
		    mg_send_status(conn, BAD_REQUEST_CODE);
        }
        else
        {
            mg_printf(conn,
						"<p style=\"color:green\">OK!</p>\r\n"
						"<p>Upload %lld bytes</p>\r\n"
						"</form>"
						 "</div>"
	                    "</body>"
	                    "</html>",tFrom.filesize);

            My_System("write_bg_pic.sh");
        }
    }
}

long long CWeb::get_time_ms()
{
    int err = 0;
    struct timespec ts;
    err = ::clock_gettime(CLOCK_MONOTONIC, &ts);
    if (err < 0)
    {
        return -1;
    }
    return (long long)ts.tv_sec * 1000 + (long long)ts.tv_nsec / 1000000;
}

static void update_bmp_preview_file(void)
{

    char buf[640*1024];
    int len = 0;
    int fd = ::open("/dev/videoip", O_RDWR);
    if (-1 != fd)
    {
        const char* cmd = "240 1\n";
        len = ::write(fd,cmd,::strlen(cmd));

        ::close(fd);
    }
    fd = open("/dev/videoip", O_RDONLY);
    if (-1 != fd)
    {
        FILE* pfd = fopen(MJPEG_TMP_BMP_FILE, "wb");
        if (NULL != pfd)
        {
            while (1)
            {
                len = ::read(fd, buf, sizeof(buf));
                if (len > 0)
                {
                    fwrite(buf, 1, len, pfd);
                }
                else
                {
                    break;
                }
            }
            fclose(pfd);
        }
        close(fd);
    }
}

void CWeb::update_jpg_preview_file(void)
{
    My_System("bmp2jpg "MJPEG_TMP_BMP_FILE" "MJPEG_TMP_JPG_FILE";rm -f "MJPEG_TMP_BMP_FILE);
    s_mjpegSeq++;
}


int CWeb::SendBmpPic(struct mg_connection *conn, const char *path)
{
	char buf[3072] = {0};
    struct stat st;
    int n;
    FILE *fp;
    if (stat(path, &st) == 0 && (fp = fopen(path, "rb")) != NULL)
    {
        mg_printf(conn, "--w00t\r\nContent-Type: application/x-bmp\r\n"
                "Content-Length: %lu\r\n\r\n", (unsigned long) st.st_size);
        while ((n = fread(buf, 1, sizeof(buf), fp)) > 0)
        {
            int write_ret = mg_write(conn, buf, n);
            if(write_ret <= 0)
            {
            	printf("write error\n");
            	fclose(fp);
				return 0;
            }
            ::memset(buf,0,sizeof(buf));
            //usleep(100);
        }
        fclose(fp);
        mg_write(conn, "\r\n", 2);
    }
    else
    {
		printf("send file error\n");
    }
	return 1;
}


int CWeb::send_bmp_file(struct mg_connection *conn,const char * picpath)
{
	mg_printf(conn, "%s",
								"HTTP/1.1 200 OK\r\n" "Cache-Control: no-cache\r\n"
								"Pragma: no-cache\r\nExpires: Thu, 01 Dec 1994 16:00:00 GMT\r\n"
								"Connection: close\r\nContent-Type: multipart/x-mixed-replace; "
								"boundary=--w00t\r\n\r\n");
	SendBmpPic(conn,picpath);
	return 0;
}

int CWeb::CapturebmpReqHandler(struct mg_connection *conn, void *cbdata)
{
    if (s_mjpegUsrCnt == 0)
    {
        long long cur = get_time_ms();
        if (cur - s_LastUpdataTime > s_mjpegIntevalMs)
        {
            s_BmpMutex.Lock();
            update_bmp_preview_file();
            s_BmpMutex.Unlock();
            s_LastUpdataTime = cur;
        }
    }

    s_BmpMutex.Lock();
    My_System("cp "MJPEG_TMP_BMP_FILE" "CAPTURE_BMP_FILE);
    s_BmpMutex.Unlock();

	send_bmp_file(conn,CAPTURE_BMP_FILE);

    return 1;
}

int CWeb::CapturejpgReqHandler(struct mg_connection *conn, void *cbdata)
{
    BC_INFO_LOG("enter the uri hander: /capture.jpg \n");

	if (s_mjpegUsrCnt == 0)
    {
        long long cur = get_time_ms();
        if (cur - s_LastUpdataTime > s_mjpegIntevalMs)
        {
        	BC_INFO_LOG("cur == %d\tg_last_update_time == %d\n",cur,s_LastUpdataTime);
            s_BmpMutex.Lock();
            update_bmp_preview_file();
            s_BmpMutex.Unlock();

            s_MjpegMutex.Lock();
            update_jpg_preview_file();
            s_MjpegMutex.Unlock();
            s_LastUpdataTime = cur;
        }
   	}
    s_MjpegMutex.Lock();
    My_System("cp "MJPEG_TMP_JPG_FILE" "CAPTURE_JPG_FILE);
    s_MjpegMutex.Unlock();

	send_jpg_file(conn,CAPTURE_JPG_FILE);

    return 1;
}

int CWeb::ExportHanndle(struct mg_connection *conn, void *cbdata)
{
    const struct mg_request_info *pRequest = mg_get_request_info(conn);
    if(strcmp(pRequest->request_method, "GET") == 0)
    {
        string strCmd = "/usr/local/bin/export_settings.sh ";
        char method[MAX_PARAM_LEN] = {0};
        mg_get_var_from_querystring(conn, "method", method, MAX_PARAM_LEN);
        strCmd += method;
        My_System(strCmd.c_str());

        mg_printf(conn, "%s",
                "HTTP/1.1 200 OK\r\n" "Cache-Control: no-cache\r\n"
                "Pragma: no-cache\r\nExpires: Thu, 01 Dec 1994 16:00:00 GMT\r\n"
                "Connection: close\r\nContent-Type: multipart/x-mixed-replace;\r\n"
                "Content-Disposition:attachment;filename=\"settings.tar.gz\"\r\n");
        mg_send_file(conn, "/dev/shm/settings.tar.gz");
        return 1;
    }
    return 0;
}

int CWeb::ImportHanndle(struct mg_connection *conn, void *cbdata)
{
    const struct mg_request_info *pRequest = mg_get_request_info(conn);
    if(strcmp(pRequest->request_method, "POST") == 0)
    {
        struct T_FromInfo tFrom;
        string strCmd = "/usr/local/bin/import_settings.sh /dev/shm/settings.tar.gz";
        if(!SaveUploadFile(conn, "/dev/shm/", "settings.tar.gz", &tFrom))
        {
            BC_INFO_LOG("ImportHanndle upload file error");
            send_http_error_rsp(conn);
        }
        else
        {
            BC_INFO_LOG("ImportHanndle upload file OK");
            My_System(strCmd.c_str());
            send_http_ok_rsp(conn);
            return 1;
        }
    }
    return 0;
}

int CWeb::LogHanndle(struct mg_connection *conn, void *cbdata)
{
    const struct mg_request_info *pRequest = mg_get_request_info(conn);
    if(strcmp(pRequest->request_method, "GET") == 0)
    {
        // mg_printf(conn, "%s",
        //         "HTTP/1.1 200 OK\r\n" "Cache-Control: no-cache\r\n"
        //         "Pragma: no-cache\r\nExpires: Thu, 01 Dec 1994 16:00:00 GMT\r\n"
        //         "Connection: close\r\n"
        //         "Content-Disposition:attachment;filename=\"log.txt\"\r\n");
        mg_send_file(conn, "/var/log/messages");
        return 1;
    }
    return 0;
}

void *CWeb::MjpegStreamThread(void *param)
{
    struct stat st;
    int n;
    long long cur = 0;
    long long next = 0;

    while(1)
    {
        cur = get_time_ms();
        if (next == 0)
        {
            next = cur;
        }

        if (s_mjpegUsrCnt > 0 && mjpeg_enable)
        {
#if 1
            int fd = ::open("/sys/devices/platform/videoip/State", O_RDONLY);
            char vstat[32];
            int statlen = 0;
            vstat[0] = '\0';
            if (-1 != fd)
            {
                statlen = ::read(fd, vstat, sizeof(vstat));
                if (statlen > 0)
                {
                    vstat[statlen] = '\0';
                }
                ::close(fd);
            }
            if (0 == strncasecmp("OPERATING", vstat, strlen("OPERATING")))
            {
#endif
                s_BmpMutex.Lock();
                update_bmp_preview_file();
                s_BmpMutex.Unlock();

                s_MjpegMutex.Lock();

                update_jpg_preview_file();

                s_LastUpdataTime = cur;
                s_MjpegMutex.Unlock();
#if 1
            }
#endif
        }

        if (cur < next)
        {
            usleep(1000 * (next - cur));
        }
        else
        {
            sched_yield();
        }

        next += s_mjpegIntevalMs;
    }
    return NULL;
}


void CWeb::P3kWebsocketHandle(struct mg_connection *conn, char *data, size_t len)
{
    CMutexLocker locker(&s_p3kmutex);
    BC_INFO_LOG("websocket get data is <%s>", data);
    if((s_p3kSocket < 0)
        || (s_p3kStatus != 1))
    {
        BC_INFO_LOG("p3k socket error");
        return;
    }

	int maxfd;
	fd_set Writefds;

	maxfd = s_p3kSocket + 1;
	FD_ZERO(&Writefds);
	FD_SET(s_p3kSocket, &Writefds);

	int nret = select(maxfd, NULL, &Writefds, NULL, NULL);
	if(nret < 0)
	{
		BC_INFO_LOG("P3kWebsocketHandle select failed");
	}

	if(nret > 0)
	{
		if(FD_ISSET(s_p3kSocket,&Writefds))
		{
            //CMutexLocker locker(&s_p3kmutex);
            int WriteSize = write(s_p3kSocket, data, len - 1);
			if(WriteSize < 0)
			{
				BC_INFO_LOG("P3kWebsocketHandle send data failed");
			}
		}
	}

}

bool CWeb::P3kConnect()
{
    int nret;
	struct sockaddr_in tServerAddr;
    struct sockaddr_in tClientAddr;

	// ?????????sockaddr?????????
    memset(&tServerAddr, 0, sizeof(tServerAddr));
    tServerAddr.sin_family = AF_INET;
    tServerAddr.sin_port = htons(6001);
    tServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    memset(&tClientAddr, 0, sizeof(tClientAddr));
    tClientAddr.sin_family = AF_INET;
    tClientAddr.sin_port = htons(6002);
    tClientAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    s_p3kSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(s_p3kSocket < 0)
    {
        BC_ERROR_LOG("socket create error");
        close(s_p3kSocket);
        return false;
    }

    int op = 1;
    nret = setsockopt(s_p3kSocket, SOL_SOCKET, SO_REUSEADDR, (void *)&op, sizeof(op));
    if(nret < 0)
    {
        BC_ERROR_LOG("socket ReuseAddr error");
        close(s_p3kSocket);
        return false;
    }

    int nBufSize = 0;
    nret = setsockopt(s_p3kSocket, SOL_SOCKET, SO_SNDBUF, (const char*)&nBufSize, sizeof(nBufSize));
    if(nret < 0)
    {
        BC_ERROR_LOG("socket NO Delay error");
        close(s_p3kSocket);
        return false;
    }

    // bind
    nret = bind(s_p3kSocket, (struct sockaddr *)&tClientAddr, sizeof(tClientAddr));
    if(nret < 0)
    {
        BC_ERROR_LOG("socket bind error");
        close(s_p3kSocket);
        return false;
    }

	// ???????????????
    nret = connect(s_p3kSocket, (struct sockaddr *)&tServerAddr, sizeof(tServerAddr));
    if(nret < 0)
    {
        //BC_ERROR_LOG("connect error");
        close(s_p3kSocket);
        s_p3kSocket = -1;
        return false;
    }
    else
    {
        BC_INFO_LOG("reconnect OK!");
        return true;
    }
}

void *CWeb::P3kCommunicationThread(void *arg)
{
    int nret;
	int maxfd = -1;
	fd_set Readfds;

    {
        CMutexLocker locker(&s_p3kmutex);
    	// ???????????????
    	while(!P3kConnect())
        {
            sleep(1);
        }

    	// ?????????p3k??????
    	char aFlag[KEY_VALUE_SIZE] = {0};
    	char aRecv[KEY_VALUE_SIZE] = {0};

        strncpy(aFlag, "#\r", strlen("#\r"));
        int len = write(s_p3kSocket, aFlag, strlen(aFlag));
        if(len < 0)
        {
            BC_INFO_LOG("p3k init write faild");
            close(s_p3kSocket);
            return NULL;
        }

        len = read(s_p3kSocket, aRecv, KEY_VALUE_SIZE);
        if(len < 0)
        {
            BC_INFO_LOG("p3k init read faild");
            close(s_p3kSocket);
            return NULL;
        }
        else
    	{
    	    BC_INFO_LOG("aRecv is <%s>", aRecv);
    		if(strncmp(aRecv, "~01@ OK\r", strlen("~01@ OK\r")) != 0)
    		{
    			BC_INFO_LOG("p3k init is check failed");
    	    	close(s_p3kSocket);
    	        return NULL;
    		}

            s_p3kStatus = 1;
    	}
    }

    while(1)
    {
        int count = 0;
        FD_ZERO(&Readfds);
    	FD_SET(s_p3kSocket, &Readfds);
    	while(1)
    	{
    		char aBuff[MG_READ_BUFSIZE] = {0};
    		maxfd = s_p3kSocket + 1;

    		nret = select(maxfd, &Readfds, NULL, NULL, NULL);
    		if(nret < 0)
    		{
    		    CMutexLocker locker(&s_p3kmutex);
    			BC_INFO_LOG("p3k read error");
    			close(s_p3kSocket);
                s_p3kSocket = -1;
                break;
    		}

    	    if(FD_ISSET(s_p3kSocket,&Readfds))
            {
                int ret = read(s_p3kSocket, aBuff, MG_READ_BUFSIZE);
                string strP3kReq = aBuff;
    			if(ret < 0)
    			{
    				BC_INFO_LOG("p3k read data failed");
    				continue;
    			}
                else if(ret == 0)
                {
                    CMutexLocker locker(&s_p3kmutex);
                    BC_INFO_LOG("p3k is close");
                    close(s_p3kSocket);
                    s_p3kSocket = -1;
                    break;
                }
                else
                {
                    int i = 0;
                    CStringSpliter split(strP3kReq);
                    split.Split("\r\n");

                    for(i; i < split.Size(); i++)
                    {
                        string strTmp = "";
                        if(split[i].find("~01@KDS-CFG-MODIFY") != string::npos)
                        {
                            continue;
                        }

                        if(split[i].empty())
                        {
                            continue;
                        }
                        strTmp = split[i];
                        strTmp += "\n";
                        Send_Data_To_ALLWebsocket(strTmp.c_str(), strTmp.length());
                    }
                }
            }
    	}

        {
            CMutexLocker locker(&s_p3kmutex);
            while(!P3kConnect())
            {
                close(s_p3kSocket);
                s_p3kSocket = -1;

                sleep(1);
                count++;
                if(count > 2)
                {
                    BC_ERROR_LOG("reconnect failed!");
                    return NULL;
                }
            }
        }
    }
}


void CWeb::CloseP3kSocket()
{
    close(s_p3kSocket);
}


