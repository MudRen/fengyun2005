// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <room.h>
inherit "/d/phoenix/ann_door_room.c";
string look_stone();

void create()
{
	set("short", "墨泉");
    set("long", @LONG
行至此处，已是谷底绝境，四面乱石堆雪，从离音谷地留下的水在这里渗
入一个浑然天成的石坑而渐渐汇集，清澈透亮的水因泉底的大黑石而显出苍墨
之色，泉边长满了黑碧诱人的石精。
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/herb":2,
	__DIR__"obj/rock":1,
	]));
	set("item_desc", ([
	"乱石":"四面的乱石隐隐透出人工布置的痕迹。\n",
	"石精":"一株株石精从石缝中长出，缤纷美丽。\n",
	]) );

	
    set("resource/water", 1);
    set("liquid/container", "石坑");   
	
	set("exits",([
  		"westup" : "pathb",
  		"northup" : "peak13",
	]) );

    create_door("northup","rock","大石","southdown",DOOR_CLOSED);

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",10);
	set("coor/y",50);
	set("coor/z",40);
	setup();
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


