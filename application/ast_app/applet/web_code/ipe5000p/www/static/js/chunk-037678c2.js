(window["webpackJsonp"]=window["webpackJsonp"]||[]).push([["chunk-037678c2"],{"466d":function(t,e,s){"use strict";var i=s("d784"),a=s("825a"),n=s("50c4"),o=s("1d80"),r=s("8aa5"),l=s("14c3");i("match",1,(function(t,e,s){return[function(e){var s=o(this),i=void 0==e?void 0:e[t];return void 0!==i?i.call(e,s):new RegExp(e)[t](String(s))},function(t){var i=s(e,t,this);if(i.done)return i.value;var o=a(t),c=String(this);if(!o.global)return l(o,c);var d=o.unicode;o.lastIndex=0;var p,h=[],u=0;while(null!==(p=l(o,c))){var f=String(p[0]);h[u]=f,""===f&&(o.lastIndex=r(c,n(o.lastIndex),d)),u++}return 0===u?null:h}]}))},"848a":function(t,e,s){},"9f7c":function(t,e,s){"use strict";s("e075")},a15b:function(t,e,s){"use strict";var i=s("23e7"),a=s("44ad"),n=s("fc6a"),o=s("a640"),r=[].join,l=a!=Object,c=o("join",",");i({target:"Array",proto:!0,forced:l||!c},{join:function(t){return r.call(n(this),void 0===t?",":t)}})},b2c7:function(t,e,s){"use strict";var i=function(){var t=this,e=t.$createElement,s=t._self._c||e;return s("label",{staticClass:"radio-model",class:{"is-disabled":t.disabled}},[s("span",{staticClass:"radio_input",class:{"is-checked":t.model===t.label}},[s("span",{staticClass:"radio__inner"}),s("input",{directives:[{name:"model",rawName:"v-model",value:t.model,expression:"model"}],attrs:{type:"radio",disabled:t.disabled,name:t.name},domProps:{value:t.label,checked:t._q(t.model,t.label)},on:{change:[function(e){t.model=t.label},t.handleChange]}})]),s("span",{staticClass:"radio__label",on:{keydown:function(t){t.stopPropagation()}}},[t._t("default"),t.$slots.default?t._e():[t._v(t._s(t.isEmpty?"":t.label))]],2)])},a=[],n={name:"radioComponent",props:{label:{type:String,default:""},disabled:{type:Boolean,default:!1},name:String,value:{},isEmpty:{type:Boolean,default:!1}},computed:{model:{get:function(){return this.value},set:function(t){this.$emit("input",t)}}},methods:{handleChange:function(){var t=this;this.$nextTick((function(){t.$emit("change",t.model)}))}}},o=n,r=(s("9f7c"),s("2877")),l=Object(r["a"])(o,i,a,!1,null,null,null);e["a"]=l.exports},c8d8:function(t,e,s){"use strict";s.r(e);var i=function(){var t=this,e=t.$createElement,s=t._self._c||e;return s("div",{staticClass:"main-setting"},[s("div",{staticClass:"setting-model"},[s("h3",{staticClass:"setting-model-title"},[t._v("Interface Settings")]),s("table",{staticClass:"table"},[t._m(0),s("tbody",[s("tr",[s("th",[t._v("Stream")]),s("th",[t._v("Media")]),s("th",[t._v("N/A")]),s("th",[t._v("N/A")]),s("th",[s("v-switch",{staticStyle:{width:"120px"},attrs:{"active-value":"1","inactive-value":"0"},model:{value:t.ipMode0,callback:function(e){t.ipMode0=e},expression:"ipMode0"}})],1),s("th",[s("div",{staticStyle:{position:"relative"}},[s("input",{directives:[{name:"model",rawName:"v-model",value:t.ipInfo0[0],expression:"ipInfo0[0]"}],staticClass:"setting-text",staticStyle:{width:"140px"},attrs:{type:"text",disabled:"1"===t.ipMode0},domProps:{value:t.ipInfo0[0]},on:{input:function(e){e.target.composing||t.$set(t.ipInfo0,0,e.target.value)}}}),2===t.ipInfo0Error?s("span",{staticClass:"range-alert",staticStyle:{top:"36px","white-space":"nowrap"}},[t._v("Please enter a valid address")]):t._e()])]),s("th",[s("div",{staticStyle:{position:"relative"}},[s("input",{directives:[{name:"model",rawName:"v-model",value:t.ipInfo0[1],expression:"ipInfo0[1]"}],staticClass:"setting-text",staticStyle:{width:"140px"},attrs:{type:"text",disabled:"1"===t.ipMode0},domProps:{value:t.ipInfo0[1]},on:{input:function(e){e.target.composing||t.$set(t.ipInfo0,1,e.target.value)}}}),1===t.ipInfo0Error?s("span",{staticClass:"range-alert",staticStyle:{top:"36px","white-space":"nowrap"}},[t._v("Please enter a valid address")]):t._e()])]),s("th",[s("div",{staticStyle:{position:"relative"}},[s("input",{directives:[{name:"model",rawName:"v-model",value:t.ipInfo0[2],expression:"ipInfo0[2]"}],staticClass:"setting-text",staticStyle:{width:"140px"},attrs:{type:"text",disabled:"1"===t.ipMode0},domProps:{value:t.ipInfo0[2]},on:{input:function(e){e.target.composing||t.$set(t.ipInfo0,2,e.target.value)}}}),3===t.ipInfo0Error?s("span",{staticClass:"range-alert",staticStyle:{top:"36px","white-space":"nowrap"}},[t._v("Please enter a valid address")]):t._e()])])]),s("tr",[s("th",[t._v("P3K & Gateway")]),s("th",[s("el-select",{staticStyle:{width:"100px"},model:{value:t.configPort0,callback:function(e){t.configPort0=e},expression:"configPort0"}},[s("el-option",{attrs:{value:"0",label:"Media"}}),s("el-option",{attrs:{value:"1",label:"Service"}})],1)],1),s("th",[s("v-switch",{staticStyle:{width:"120px"},model:{value:t.p3k802Q,callback:function(e){t.p3k802Q=e},expression:"p3k802Q"}})],1),s("th",[s("el-input-number",{staticStyle:{width:"80px"},attrs:{disabled:!t.p3k802Q,"controls-position":"right",max:4093,min:2},model:{value:t.danteTag1,callback:function(e){t.danteTag1=e},expression:"danteTag1"}})],1),s("th",[s("v-switch",{staticStyle:{width:"120px"},attrs:{"active-value":"1",disabled:"0"===t.configPort0&&!t.p3k802Q,"inactive-value":"0"},model:{value:t.ipMode1,callback:function(e){t.ipMode1=e},expression:"ipMode1"}})],1),s("th",[s("div",{staticStyle:{position:"relative"}},[s("input",{directives:[{name:"model",rawName:"v-model",value:t.ipInfo1[0],expression:"ipInfo1[0]"}],staticClass:"setting-text",staticStyle:{width:"140px"},attrs:{type:"text",disabled:"1"===t.ipMode1||"0"===t.configPort0&&!t.p3k802Q},domProps:{value:t.ipInfo1[0]},on:{input:function(e){e.target.composing||t.$set(t.ipInfo1,0,e.target.value)}}}),2!==t.ipInfo1Error||"0"===this.configPort0&&!this.p3k802Q?t._e():s("span",{staticClass:"range-alert",staticStyle:{top:"36px","white-space":"nowrap"}},[t._v("Please enter a valid address")])])]),s("th",[s("div",{staticStyle:{position:"relative"}},[s("input",{directives:[{name:"model",rawName:"v-model",value:t.ipInfo1[1],expression:"ipInfo1[1]"}],staticClass:"setting-text",staticStyle:{width:"140px"},attrs:{type:"text",disabled:"1"===t.ipMode1||"0"===t.configPort0&&!t.p3k802Q},domProps:{value:t.ipInfo1[1]},on:{input:function(e){e.target.composing||t.$set(t.ipInfo1,1,e.target.value)}}}),1!==t.ipInfo1Error||"0"===this.configPort0&&!this.p3k802Q?t._e():s("span",{staticClass:"range-alert",staticStyle:{top:"36px","white-space":"nowrap"}},[t._v("Please enter a valid address")])])]),s("th",[s("div",{staticStyle:{position:"relative"}},[s("input",{directives:[{name:"model",rawName:"v-model",value:t.ipInfo1[2],expression:"ipInfo1[2]"}],staticClass:"setting-text",staticStyle:{width:"140px"},attrs:{type:"text",disabled:"1"===t.ipMode1||"0"===t.configPort0&&!t.p3k802Q},domProps:{value:t.ipInfo1[2]},on:{input:function(e){e.target.composing||t.$set(t.ipInfo1,2,e.target.value)}}}),3!==t.ipInfo1Error||"0"===this.configPort0&&!this.p3k802Q?t._e():s("span",{staticClass:"range-alert",staticStyle:{top:"36px","white-space":"nowrap"}},[t._v("Please enter a valid address")])])])]),1===this.$global.deviceType?s("tr",[s("th",[t._v("Dante")]),s("th",[s("el-select",{staticStyle:{width:"100px"},model:{value:t.configPort1,callback:function(e){t.configPort1=e},expression:"configPort1"}},[s("el-option",{attrs:{value:"0",label:"Media"}}),s("el-option",{attrs:{value:"1",label:"Service"}})],1)],1),s("th",[s("v-switch",{staticStyle:{width:"120px"},model:{value:t.dante802Q,callback:function(e){t.dante802Q=e},expression:"dante802Q"}})],1),s("th",[s("el-input-number",{staticStyle:{width:"80px"},attrs:{disabled:!t.dante802Q,"controls-position":"right",max:4093,min:2},model:{value:t.danteTag2,callback:function(e){t.danteTag2=e},expression:"danteTag2"}})],1)]):t._e()])])]),s("div",{staticClass:"setting"},[s("div",{staticClass:"radio-setting",staticStyle:{"margin-bottom":"0"}},[s("span",{staticClass:"setting-model-title"},[t._v("IP Casting Mode")]),s("div",[s("radio-component",{attrs:{label:"1"},model:{value:t.castMode,callback:function(e){t.castMode=e},expression:"castMode"}},[t._v("Unicast ")]),s("radio-component",{attrs:{label:"2"},model:{value:t.castMode,callback:function(e){t.castMode=e},expression:"castMode"}},[t._v("Multicast ")])],1)])]),s("div",{staticClass:"setting"},[s("span",{staticClass:"setting-title"},[t._v("TTL")]),s("div",{staticClass:"setting-title"},[s("el-input-number",{attrs:{"controls-position":"right",max:255,min:1,disabled:"1"==t.castMode},model:{value:t.ttl,callback:function(e){t.ttl=e},expression:"ttl"}})],1)]),s("div",{staticClass:"setting-model"},[s("h3",{staticClass:"setting-model-title"},[t._v("TCP/UDP Management")]),s("div",{staticClass:"setting"},[s("span",{staticClass:"setting-title"},[t._v("TCP Port")]),s("div",{staticStyle:{position:"relative"}},[s("el-input-number",{attrs:{"controls-position":"right",max:5099,min:5e3},model:{value:t.tcp,callback:function(e){t.tcp=e},expression:"tcp"}}),t.portUse?s("span",{staticClass:"range-alert",staticStyle:{top:"36px","white-space":"nowrap"}},[t._v("Port already in use")]):t._e()],1)]),s("div",{staticClass:"setting"},[s("span",{staticClass:"setting-title"},[t._v("UDP Port")]),s("el-input-number",{attrs:{"controls-position":"right",min:5e4,max:50999},model:{value:t.udp,callback:function(e){t.udp=e},expression:"udp"}})],1)]),s("footer",[s("button",{staticClass:"btn btn-primary",on:{click:t.save}},[t._v("SAVE ")])]),s("el-dialog",{attrs:{title:"RESTART",visible:t.dialogVisibleReset,width:"500px"},on:{"update:visible":function(e){t.dialogVisibleReset=e}}},[s("p",{staticClass:"dialog-second-title"},[t._v("Restart for new settings to take effect. ")]),s("p",{staticClass:"dialog-second-title"},[t._v("Do you want to restart now?")]),s("span",{staticClass:"dialog-footer",attrs:{slot:"footer"},slot:"footer"},[s("button",{staticClass:"btn btn-primary",on:{click:function(e){t.dialogVisibleReset=!1,t.restart()}}},[t._v("RESTART")]),s("button",{staticClass:"btn btn-primary",on:{click:function(e){t.dialogVisibleReset=!1}}},[t._v("LATER")])])])],1)},a=[function(){var t=this,e=t.$createElement,s=t._self._c||e;return s("thead",[s("tr",[s("th",[t._v("Service Name")]),s("th",[t._v("Port")]),s("th",[t._v("802.1Q")]),s("th",[t._v("VLAN Tag")]),s("th",[t._v("DHCP")]),s("th",[t._v("IP Address")]),s("th",[t._v("Mask Address")]),s("th",[t._v("Gateway Address")])])])}],n=(s("ac1f"),s("841c"),s("1276"),s("466d"),s("a15b"),s("b2c7")),o=s("2ef0");function r(t,e,s){return l(e)?!p(t)||h(t,e)?2:f(s)?t===s?4:u(t,e,s)?0:5:3:1}function l(t){var e=0,s=0,i=0,a=0,n=!1;if("0.0.0.0"===t)return!1;var o=t.split(".");if(4!==o.length)return!1;for(e=0;e<4;e++){if(!0===isNaN(o[e]))return!1;if(s=parseInt(o[e]),s<0||s>255)return!1;if(!0===n&&0!==s)return!1;if(i=c(s),a=d(s),i<a)return!1;i<8&&(n=!0)}return!0}function c(t){var e=0,s=[128,64,32,16,8,4,2,1];for(e=0;e<s.length;e++)if(0===(t&s[e]))return e;return s.length}function d(t){var e=0,s=[1,2,4,8,16,32,64,128];for(e=0;e<s.length;e++)if((t&s[e])>>e===1)return s.length-e-1;return-1}function p(t){var e=t.split("/");if(e.length>2)return!1;if(2===e.length){var s=parseInt(e[1]);if(s<=0||s>32)return!1}if("0.0.0.0"===e[0]||"255.255.255.255"===e[0])return!1;var i=e[0].split(".");if(4!==i.length)return!1;for(var a=0;a<4;a++){if(isNaN(i[a])||""===i[a])return!1;var n=parseInt(i[a]);if(n<0||n>255)return!1}return!0}function h(t,e){var s=0,i=e.split("."),a=t.split(".");if(parseInt(a[0])>223||127===parseInt(a[0]))return!0;for(s=0;s<4;s++)if(parseInt(i[s])<255)break;var n=parseInt(a[s]),o=255-parseInt(i[s]),r=n&o;if(0!==r&&r!==o)return!1;if(3===s)return!0;if(2===s){if(0===a[3]&&0===r||255===a[3]&&r===o)return!0}else if(1===s){if(0===r&&0===a[3]&&0===a[2]||r===o&&255===a[3]&&255===a[2])return!0}else if(0===s&&(0===r&&0===a[3]&&0===a[2]&&0===a[1]||r===o&&255===a[3]&&255===a[2]&&255===a[1]))return!0;return!1}function u(t,e,s){if(f(t)&&f(e)&&f(s)){var i=t.split("."),a=e.split("."),n=s.split("."),o=[],r=[],l=[];return o[0]=255&parseInt(i[0]),o[1]=255&parseInt(i[1]),o[2]=255&parseInt(i[2]),o[3]=255&parseInt(i[3]),l[0]=255&parseInt(n[0]),l[1]=255&parseInt(n[1]),l[2]=255&parseInt(n[2]),l[3]=255&parseInt(n[3]),r[0]=255&parseInt(a[0]),r[1]=255&parseInt(a[1]),r[2]=255&parseInt(a[2]),r[3]=255&parseInt(a[3]),!(o[3]&0===~r[3]||o[3]&255===~r[3])&&((o[0]&r[0])===(l[0]&r[0])&&(o[1]&r[1])===(l[1]&r[1])&&(o[2]&r[2])===(l[2]&r[2])&&(o[3]&r[3])===(l[3]&r[3])||"0.0.0.0"===s)}return!1}function f(t){var e=/^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/;return e.test(t)}var v=r,g={name:"autoSwitch",components:{radioComponent:n["a"]},data:function(){return{dialogVisibleReset:!1,port1:"1",port2:"1",ipMode0:"0",ipMode1:"0",ipInfo0:[],ipInfo1:[],configPort0:"0",configPort1:"0",danteTag:"",tcp:5e3,serverTcpPort:"5001",udp:5e4,castMode:"1",multicastAddress:"0,0,0,0",ttl:64,danteTag1:2,danteTag2:2,p3k802Q:!1,dante802Q:!1,ipInfo0Error:0,ipInfo1Error:0,setIpFlag:!1,rs232Port:0,portUse:!1}},created:function(){this.$socket.setCallback(this.handleMsg),this.$socket.sendMsg("#NET-DHCP? 0"),this.$socket.sendMsg("#NET-DHCP? 1"),this.$socket.sendMsg("#NET-CONFIG? 0"),this.$socket.sendMsg("#NET-CONFIG? 1"),this.$socket.sendMsg("#KDS-GW-ETH? 0"),this.$socket.sendMsg("#KDS-VLAN-TAG? 0"),this.$socket.sendMsg("#KDS-METHOD? "),this.$socket.sendMsg("#KDS-MULTICAST? "),this.$socket.sendMsg("#ETH-PORT? TCP"),this.$socket.sendMsg("#ETH-PORT? UDP"),this.$socket.sendMsg("#COM-ROUTE? *"),1===this.$global.deviceType&&(this.$socket.sendMsg("#KDS-GW-ETH? 1"),this.$socket.sendMsg("#KDS-VLAN-TAG? 1"))},methods:{handleMsg:function(t){-1===t.search(/@NET-DHCP /i)?-1===t.search(/@NET-CONFIG /i)?-1===t.search(/@KDS-VLAN-TAG /i)?-1===t.search(/@KDS-GW-ETH /i)?-1===t.search(/@KDS-METHOD /i)?-1===t.search(/@KDS-MULTICAST /i)?-1===t.search(/@COM-ROUTE /i)?-1!==t.search(/@ETH-PORT /i)&&this.handleETHPort(t):this.handleRs232Gateway(t):this.handleMulticast(t):this.handleIpCastMode(t):this.handlePortConfig(t):this.handleDanteTag(t):this.handleIP(t):this.handleIPMode(t)},handleIPMode:function(t){var e=t.split(" ")[1].split(","),s="1"===e[1]?e[1]:"0";this["ipMode"+e[0]]=s,this.setIpFlag&&(this.setIpFlag=!1,this.dialogVisibleReset=!0)},handleIP:function(t){var e=t.split(" ")[1],s="ipInfo"+e[0],i=[],a=/(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)/g,n=e.match(a);i.push(n[0]||""),i.push(n[1]||""),i.push(n[2]||""),this[s]=i},handleDanteTag:function(t){var e=t.split(" ")[1].split(",");if("0"===e[0]){var s=parseInt(e[1]);this.p3k802Q=1!==s,1!==s&&(this.danteTag1=s)}else if("1"===e[0]){var i=parseInt(e[1]);this.dante802Q=1!==i,1!==i&&(this.danteTag2=i)}},handlePortConfig:function(t){var e=t.split(" ")[1].split(",");this["configPort"+e[0]]=e[1]},handleETHPort:function(t){if(-1===t.search(/err/gi)){var e=t.toLowerCase().split(" ")[1].split(",");this[e[0]]=parseInt(e[1])}},handleIpCastMode:function(t){this.castMode=t.split(" ")[1]},handleMulticast:function(t){var e=t.split(" ")[1].split(",");this.ttl=parseInt(e[1])},save:Object(o["debounce"])((function(){this.portUse=!1,this.validIP()&&(this.tcp!=this.rs232Port?(this.setPortConfig(),this.setIpCastingMode(),this.setTcpUDP(),this.setIp()):this.portUse=!0)}),2e3,{leading:!0,trailing:!0}),setPortConfig:function(){this.$socket.sendMsg("#KDS-GW-ETH 0,"+this.configPort0),this.$socket.sendMsg("#KDS-VLAN-TAG 0,"+(this.p3k802Q?this.danteTag1:1)),1===this.$global.deviceType&&(this.$socket.sendMsg("#KDS-GW-ETH 1,"+this.configPort1),this.$socket.sendMsg("#KDS-VLAN-TAG 1,"+(this.dante802Q?this.danteTag2:1)))},setIpCastingMode:function(){this.$socket.sendMsg("#KDS-METHOD "+this.castMode),"2"===this.castMode&&this.$socket.sendMsg("#KDS-MULTICAST 225.225.0.10,".concat(this.ttl))},setTcpUDP:function(){this.$socket.sendMsg("#ETH-PORT TCP,"+this.tcp),this.$socket.sendMsg("#ETH-PORT UDP,"+this.udp)},setIp:function(){this.setIpFlag=!0,"1"!==this.ipMode0?(this.$socket.sendMsg("#NET-DHCP 0,0"),this.$socket.sendMsg("#NET-CONFIG 0,"+this.ipInfo0.join(","))):this.$socket.sendMsg("#NET-DHCP 0,1"),("0"!==this.configPort0||this.p3k802Q)&&("1"!==this.ipMode1?(this.$socket.sendMsg("#NET-DHCP 1,0"),this.$socket.sendMsg("#NET-CONFIG 1,"+this.ipInfo1.join(","))):this.$socket.sendMsg("#NET-DHCP 1,1"))},validIP:function(){return this.ipInfo0Error=0,this.ipInfo1Error=0,("1"===this.ipMode0||(this.ipInfo0Error=this.isValidIP(this.ipInfo0[0],this.ipInfo0[1],this.ipInfo0[2]),4===this.ipInfo0Error&&alert("The IP address of Eth0 cannot be the same as the gateway address"),5===this.ipInfo0Error&&alert("The gateway address of Eth0 is not at the same network(subnet), which is defined on basis of IP address and mask address."),0===this.ipInfo0Error))&&("0"===this.configPort0&&!this.p3k802Q||"1"===this.ipMode1||(this.ipInfo1Error=this.isValidIP(this.ipInfo1[0],this.ipInfo1[1],this.ipInfo1[2]),4===this.ipInfo1Error&&alert("The IP address of Eth1 cannot be the same as the gateway address"),5===this.ipInfo1Error&&alert("The gateway address of Eth1 is not at the same network(subnet), which is defined on basis of IP address and mask address."),0===this.ipInfo1Error))},isValidIP:function(t,e,s){return v(t,e,s)},restart:function(){var t=this;this.$socket.sendMsg("#RESET"),this.dialogVisibleReset=!1,sessionStorage.removeItem("login"),setTimeout((function(){t.$msg.successAlert("Network configuration changed, please reopen the web page with the new network settings",8e3)}),1e3)},handleRs232Gateway:function(t){var e=t.split(" ");if(e[1].length>0){var s=e[1].split(",");this.rs232Port=parseInt(s[2])}}}},m=g,I=(s("f59e"),s("2877")),b=Object(I["a"])(m,i,a,!1,null,"371d19dc",null);e["default"]=b.exports},e075:function(t,e,s){},f59e:function(t,e,s){"use strict";s("848a")}}]);