#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "小桥流水");
        set("long", @LONG
一条清澈的小溪上横跨着一座木桥。桥的那边是一片茂盛的竹林。在竹林与梅
花的掩映之中，一座精巧的庄院若隐若现。侧耳倾听，琴韵丁冬，有人正在[33m抚琴[32m，
还有些女童的嬉闹笑声。
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"gate",
  		"east" : __DIR__"another_sky",
		]));
		set("item_desc",([
			"抚琴":	"园子里的抚琴你怎么"MAG"看"NOR"得到呢？应该是。。。？？\n",
		]));
        set("outdoors", "resort");

		set("coor/x",0);
		set("coor/y",-30);
		set("coor/z",0);
		setup();
       
}


void init(){
	add_action("do_listen","listen");
}



int do_listen(){
	tell_object(this_player(),CYN"
园内忽然传来一阵琴声，山之巍巍，水之洋洋，斧伐之丁丁，橹歌之矣乃，
隐隐现于指下，令人忘却了红尘的烦恼。

只闻园内有人说道：远来是客，请进翠竹山庄一叙。\n"NOR);
	this_player()->set_temp("resort_qin",1);
	return 1;
}


