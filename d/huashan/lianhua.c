#include <ansi.h>
inherit ROOM;
string dan();

void create()
{
        set("short", "莲花峰");
        set("long", @LONG
西峰因峰巅有巨石形似莲花，所以又叫莲花峰。山峰为一块完整巨石，浑然天
成。西北绝崖千仗，似刀削锯截，其陡峭巍峨、阳刚挺拔之势是华山山形之代表。
因此古人常把华山叫莲山。向东南看，可以看到镇岳宫；西南则是有名的舍身崖。
LONG
        );
    	set("exits", ([ 
        "eastdown" : __DIR__"shanlu2",
	    "southwest" : __DIR__"sheshen",
	    "southeast" : __DIR__"zhenyue",
	    "northdown" : __DIR__"fupi",
	]));
	set("objects", ([
		__DIR__"npc/zahuo" : 1,
	]));
/*    	set("item_desc", ([
    		"担子" : (: dan :),
    		"danzi" : (: dan :),
    	]));*/
	set("item_bamboo", 1);    
    	set("outdoors", "huashan");
    	set("release_hawk",1);
	set("coor/x",-75);
	set("coor/y",-55);
	set("coor/z",40);
	setup();
}

/*
string dan(){
	object me;
	me = this_player();
	if(!present("dan fan", this_object())){
		return "什么？\n";
	}
	tell_object(me, "担子两头的竹筐里摆满了各色物品，从食品到胭脂花粉应有尽有。\n");
	if(query("item_bamboo")){
		tell_object(me, "扁担横在地上，旁边是一个半旧的竹筒（ｚｈｕｔｏｎｇ）。\n");
	}	
	return "";
}
*/