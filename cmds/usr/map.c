// map.c by Silencer@fy4.

#include <ansi.h>
#include "/doc/help.h"
inherit F_CLEAN_UP;

string ngstr(string str);

int main(object me, string arg)
{
    int i;
    string file, area, room, map, room_name, room1;
    string a1, a2, a3;


    if (me->query_temp("timer/map")+2>time())
	return notify_fail("检验地图最多只能每两秒执行一次。\n");
    file = file_name(environment(me));
    //  write("file is "+file +"\n");
    if (sscanf(file,"/d/%s/%s",area,room)==2) {
	switch (area) {
	case "fywall":
	case "fycycle": area = "fycycle";  break;
	case "fy":	area = "fengyun";  break;
	case "palace":	area = "diwanggu"; break;
	case "resort":	area = "tiexue";   break;
	case "wulapo":  area = "xinjiang"; break;
	case "taoguan": area = "sanqing" ; break;
	case "guanyin": area = "tianfeng"; break;
	case "chuenyu": area = "heisong" ; break;
	case "death": 	area = "diyu"	 ; break;
	case "oldpine":	area = "laoyun" ; break;	
	case "ghost":   area = "youling"; break;
	case "xinjiang":area = "wulapo"; break;
	case "tieflag" :area = "east";	 break;
	case "eastcoast": area = "east"; break;
	case "quicksand": area = "west"; break;
	case "bawang":  area = "ehu"	;break;
	case "eren":    area = "kunlun"; break;
	case "cave": 	area = "dixia";  break;
	}

	if (area == "fengyun") {
	    if ( environment(me)->query("map")=="fyeast"){area = "fengyun_east";}
	    if ( environment(me)->query("map")=="fywest"){area = "fengyun_west";}
	    if ( environment(me)->query("map")=="fynorth"){area = "fengyun_north";}
	    if ( environment(me)->query("map")=="fysouth"){area = "fengyun_south";}
	}
	if (area == "zangbei") {
	    if ( environment(me)->query("map")=="zbeast"){area = "zangbei_east";}   
	    	else area = "zangbei_west";
	}
	
	//other areas can be added in here later...


	if (file_size(HELP_DIR + "help/maps/"+area+"_map.txt")>0) {
	    map = read_file(HELP_DIR + "help/maps/"+area+"_map.txt");
	    room_name = environment(me)->query("short");

	    room_name = ngstr(room_name);
//	    write(room_name); 
	    map = replace_string(map,room_name,BGRN HIW""+room_name+""NOR);
	    write (map);
	    write ("\n\n你现在所处地点的地名为  "+ HIR""+room_name + NOR"\n");
	    write ("此地名在地图上以"HIG"亮绿色"NOR"标出。（注意，可能有重名地点存在）\n\n\n");
	    me->set_temp("timer/map",time());
	    return 1;
	}
    }
    return notify_fail("当前地区的地图不存在。\n");
}

string ngstr(string str)
{
    int i,i2;
    string strc;
    strc=str;
    // filter color-code
    str=replace_string(str,CSI,"");

    str=replace_string(str,"2;37;0m","");

    str=replace_string(str,"41;","");
    str=replace_string(str,"42;","");
    str=replace_string(str,"43;","");
    str=replace_string(str,"44;","");
    str=replace_string(str,"45;","");
    str=replace_string(str,"46;","");
    str=replace_string(str,"47;","");
    str=replace_string(str,"1;","");
    str=replace_string(str,"30m","");
    str=replace_string(str,"31m","");
    str=replace_string(str,"32m","");
    str=replace_string(str,"33m","");
    str=replace_string(str,"34m","");
    str=replace_string(str,"35m","");
    str=replace_string(str,"36m","");
    str=replace_string(str,"37m","");
    str=replace_string(str,"38m","");
    str=replace_string(str,"40m","");
    str=replace_string(str,"41m","");
    str=replace_string(str,"42m","");
    str=replace_string(str,"43m","");
    str=replace_string(str,"44m","");
    str=replace_string(str,"45m","");
    str=replace_string(str,"46m","");
    str=replace_string(str,"47m","");
    str=replace_string(str,"1m","");

    return str;

}


int help(object me)
{
    write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 :   map[0m
[0;1;37m────────────────────────────────[0m   

指令格式：map

这个指令提供你当前区域的地图。

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}

/* 非常不完善的地图。
↓↑→←

help bat_map.txt            蝙蝠岛地图  
help chenxiang_map.txt      沉香镇地图
help daimiao_map.txt        岱庙地图
help diwanggu_map.txt       帝王谷地图
help fengyun_map.txt        风云城地图
help fugui_map.txt          富贵山庄地图
help guanwai_map.txt        关外地图
help huashan_map.txt        华山地图
help huangshan_map.txt      黄山地图
help jinan_map.txt          济南地图
help laowu_map.txt          老屋地图
help loulan_map.txt         楼兰城地图
help qianjin_map.txt        千金楼地图
help shaolin_map.txt        少林寺地图
help songshan_map.txt       嵩山地图
help taishan_map.txt        泰山地图
help wolfmount_map.txt      狼山地图
help wudang_map.txt         武当山地图
help wulapo_map.txt         乌拉泊地图
*/
