// This file for hj_wiztools.c and hj_npc_quest.c(the no.1 , seller)
// 现有两个文件包含本文件：hj_wiztools.c 及 hj_npc_quest.c 。
// 实际上，两份文件所用是不同的。统一在这里，是为了方便更改。



// ###########################################################
// ################# 下面是巫师用的复制列表 ##################
// ###########################################################

string *can_copy=({"
    \n"HIY"工具类"NOR"\n",
"dx定向水晶","fx飞翔之石","tl脱离水晶","hg回归之镜",
"qd祈祷之石","zh召唤之盒","fd发呆之旗","qz驱逐之旗",
"xr寻人水晶","kt窥探水晶","dw定位之仪",

    "\n"HIY"其他类"NOR"\n",
"wmg无名果","xrg仙人果","tqg淘气果","dlg毒龙果","ysg野生果实",
"hbs红色宝石","lvbs绿色宝石","lbs蓝色宝石","slg试炼之果",


    "\n"HIY"武器类"NOR"\n",
"qtj青铜之剑","lqj灵气之剑","byj白银之剑","ydj盈动之剑",
"hjj黄金之剑","nlj耐力之剑","xyj迅隐之剑","dhj夺魂之剑","bsj必胜之剑",
"kfsj狂风水晶","bysj暴雨水晶","llsj落雷水晶","ydsj引电水晶","gssj滚石水晶",
"fhsj飞火水晶","dhsj夺魂水晶",

    "\n"HIY"迷题物品类"NOR"\n",
"hfzs呼风之石","hyzs唤雨之石","llzs落雷之石","ydzs引电之石",
"gszs滚石之石","fhs飞火之石","dhzs夺魂之石","fhzs复活之石",

    "\n"HIY"特殊物品类(不可购买)"NOR"\n",
"srl神人令（5分钟效能）", "box宝箱",
});


mapping all=([

"dx":"定向水晶","fx":"飞翔之石","tl":"脱离水晶","hg":"回归之镜","qd":"祈祷之石",
"zh":"召唤之盒","fd":"发呆之旗","qz":"驱逐之旗","xr":"寻人水晶","kt":"窥探水晶",
"dw":"定位之仪",

"wmg":"无名果","xrg":"仙人果","tqg":"淘气果","dlg":"毒龙果","ysg":"野生果实",
"hbs":"红色宝石","lvbs":"绿色宝石","lbs":"蓝色宝石","slg":"试炼之果",


"qtj":"青铜之剑","lqj":"灵气之剑","byj":"白银之剑","ydj":"盈动之剑",
"hjj":"黄金之剑","nlj":"耐力之剑","xyj":"迅隐之剑","dhj":"夺魂之剑","bsj":"必胜之剑",


"kfsj":"狂风水晶","bysj":"暴雨水晶","llsj":"落雷水晶","ydsj":"引电水晶",
"gssj":"滚石水晶","fhsj":"飞火水晶","dhsj":"夺魂水晶",

"hfzs":"呼风之石","hyzs":"唤雨之石","llzs":"落雷之石","ydzs":"引电之石",
"gszs":"滚石之石","fhs":"飞火之石","dhzs":"夺魂之石","fhzs":"复活之石",

"srl":"神人令(5分钟的)", "box":"宝箱",

    ]);



mapping all_dir=([

"dx":"hj_obj_tools","fx":"hj_obj_tools","tl":"hj_obj_tools","hg":"hj_obj_tools",
"qd":"hj_obj_tools","zh":"hj_obj_tools","fd":"hj_obj_tools","qz":"hj_obj_tools",
"xr":"hj_obj_tools","kt":"hj_obj_tools","dw":"hj_obj_tools",

"wmg":"hj_obj_other","xrg":"hj_obj_other","tqg":"hj_obj_other",
"dlg":"hj_obj_other","ysg":"hj_obj_other","hbs":"hj_obj_other",
"lvbs":"hj_obj_other","lbs":"hj_obj_other","slg":"hj_obj_other",

"qtj":"hj_obj_weapon","lqj":"hj_obj_weapon","byj":"hj_obj_weapon","ydj":"hj_obj_weapon",
"hjj":"hj_obj_weapon","nlj":"hj_obj_weapon","xyj":"hj_obj_weapon","dhj":"hj_obj_weapon",
"bsj":"hj_obj_weapon","kfsj":"hj_obj_weapon","bysj":"hj_obj_weapon",
"llsj":"hj_obj_weapon","ydsj":"hj_obj_weapon","gssj":"hj_obj_weapon",
"fhsj":"hj_obj_weapon","dhsj":"hj_obj_weapon",

"hfzs":"hj_obj_quest","hyzs":"hj_obj_quest","llzs":"hj_obj_quest","ydzs":"hj_obj_quest",
"gszs":"hj_obj_quest","fhs":"hj_obj_quest","dhzs":"hj_obj_quest","fhzs":"hj_obj_quest",
"srl":"shenren_ling","box":"hj_box",
    ]);

mapping all_set=([

"dx":111,"fx":1,"tl":2,"hg":3,"qd":4,"zh":5,"fd":6,"qz":7,"xr":8,"kt":9, "dw":10,

"wmg":111,"xrg":1,"tqg":2,"dlg":3,"ysg":4,
"hbs":5,"lvbs":6,"lbs":7,"slg":8,

"qtj":111,"lqj":1,"byj":2,"ydj":3,
"hjj":4,"nlj":5,"xyj":6,"dhj":7,"bsj":8,

"kfsj":9,"bysj":10,"llsj":11,"ydsj":12,
"gssj":13,"fhsj":14,"dhsj":15,

"hfzs":111,"hyzs":1,"llzs":2,"ydzs":3,"gszs":4,"fhs":5,"dhzs":6,"fhzs":7,
"srl":1024, "box":1024,
// 这个 srl(神人令) 的 set 的方法已更改，这里的数值毫无意义了。
    ]);

// 在随后的时候学懂了 mapping 的用法，发现 hj_wiz_tools.c 里的
// list方案写得有够愚笨的哎……


// ###########################################################
// ################# 下面是玩家用的销售列表 ##################
// ###########################################################

mapping can_sell_tools=([   // 奇特

"dx":"定向水晶","fx":"飞翔之石","tl":"脱离水晶","hg":"回归之镜","test":"测试啦",
"qd":"祈祷之石","zh":"召唤之盒","fd":"发呆之旗","qz":"驱逐之旗","xr":"寻人水晶",
"kt":"窥探水晶","dw":"定位之仪",
    ]);

mapping can_sell_other=([   // 果品类

"wmg":"无名果","xrg":"仙人果","tqg":"淘气果","dlg":"毒龙果",
"ysg":"野生果实","slg":"试炼之果"
    ]);

mapping can_sell_weapon=([   // 兵器类

"qtj":"青铜之剑","lqj":"灵气之剑","byj":"白银之剑","ydj":"盈动之剑",
"hjj":"黄金之剑","nlj":"耐力之剑","xyj":"迅隐之剑","dhj":"夺魂之剑","bsj":"必胜之剑",
"kfsj":"狂风水晶","bysj":"暴雨水晶","llsj":"落雷水晶","ydsj":"引电水晶","gssj":"滚石水晶",
"fhsj":"飞火水晶","dhsj":"夺魂水晶"
    ]);

mapping can_sell_quest=([    // 神秘

"hfzs":"呼风之石","hyzs":"唤雨之石","llzs":"落雷之石","ydzs":"引电之石",
"gszs":"滚石之石","fhs":"飞火之石","dhzs":"夺魂之石","fhzs":"复活之石"
    ]);


// 此文件内记录各道具的价格
#include "obj_values.h"
