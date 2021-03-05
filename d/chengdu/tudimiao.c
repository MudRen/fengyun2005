// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "土地庙");
        set("long", @LONG
土地神源于远古人们对土地权属的崇拜。土地能生五谷，是人类的“衣食父母”，
因而人们祭祀土地。这庙造型简单，以两块石头为壁，一块为顶。土地庙地处北城，
周围居住的多是各行各业的劳动人民。虽然简陋但也香火鼎盛，对面便是成都有名
的杜埔草堂。
LONG
        );
	set("exits",([
  		"east" : __DIR__"beidajie2",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}