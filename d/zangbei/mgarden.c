inherit ROOM;
#include <ansi.h>

int closedoor();

void create()

{
        set("short", "后院");
        set("long", @LONG
马家的客人经常都不少。客人们吃过马太太亲手做的红烧狮子头，陪马方中下
过几盘棋后．走出院子时，都忘不了对马方中院子里种的花赞美几句。马方中总是
嘻嘻地笑着，也不客气。的确，种花是他最大的嗜好，每当秋季菊花盛开，马小宝
和马小贝就会在花从中追逐玩耍。
LONG
        );
        set("exits", ([ 
		"west":		__DIR__"mroom",
	]));
        set("item_desc", ([
        	"菊花":	"正当秋季，院子里的菊花有半人多高，绚烂多彩。\n",
        	"flower": "正当秋季，院子里的菊花有半人多高，绚烂多彩。\n",
    	]));
        set("objects", ([
        	__DIR__"npc/mafangzhong":	1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1280);
        set("coor/y",680);
        set("coor/z",0);
	set("map","zbeast");
	setup();
}


void init() {
	add_action("do_pull","pull");
	add_action("do_look","look");
	add_action("do_search","search");
}

int do_search(){
	tell_object(this_player(),"园子里的菊花长得郁郁葱葱，恐怕搜一天都不会有结果。\n");
	return 1;
}

int do_look(string arg){

	object me = this_player();
		
	if (!arg || (arg!="菊花" && arg!="flower"))	return 0;
	
	tell_object(me,"正当秋季，院子里的菊花有半人多高，把地面遮住了许多。\n");
	return 1;
}


int do_pull(string arg) {
	object me=this_player();
	object ma;
	
	if (arg== "flower" || arg == "菊花") {
		if (ma=present("ma fangzhong",this_object())) {
			tell_object(me,"马方中伸手挡住你，笑嘻嘻地说：“辣手摧花，太煞风景了吧。”\n");
			return 1;
		}
		message_vision(YEL"
$N卷起衣袖，抓住开的最茂盛的那簇菊花使劲往上一拽，菊花被连根拔起，
带起了一大块泥土，泥土之下，竟然出现了一个黑漆漆的大洞！\n"NOR,me);
		set("exits/down",__DIR__"tunnel1");
		call_out("closedoor", 15);
		return 1;
	}
	return notify_fail("你想拔/拉什么？\n");
}




int closedoor () {
	if (query("exits/down")) delete("exits/down");
	return 1;
}


