// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "古观星台");
    set("long", "与残破不堪的古瞭望台相比，古观星台虽然也历历了沧海桑田的变迁，却
依然可以称上无缺，除去搁置在角落里的仪器已沾满了斑斑锈迹，"YEL"石栏"NOR"、"YEL"石椅"NOR"
乃至于地面上刻着的玄天推演图都几近无损。躺在冰凉的地面上仰望天穹，你
仍可想象出当年钦天监众人在此观测天相、推断天机的繁华光景。
"
NOR
        );
	set("objects", ([
	__DIR__"obj/spyglass":1,
	__DIR__"obj/arcane":1,
	__DIR__"obj/rustydevice":1,
	__DIR__"npc/fon":1,
	]));
	set("item_desc", ([
	"石栏":"石栏上雕着一行细小的"YEL"文字"NOR"，很难看得清晰。\n",
	"parapet":"石栏上雕着一行细小的"YEL"文字"NOR"，很难看得清晰。\n",
	"文字":"定元五年十二月丁亥有星如弹丸，见九游旁，黄白光润，\n旬有五日而隐。\n",
	"石椅":"石椅扶手上刻着一段"YEL"铭文"NOR"，很难辨得清晰。\n",
	"chair":"石椅扶手上刻着一段"YEL"铭文"NOR"，很难辨得清晰。\n",
	"铭文":"钦天监正皇甫仲和、皇甫波江建此星台于太陨八年。\n屈指算来，这已经是四百多年前的事了。\n",
	]) );
	set("exits",([
  		"southdown" : __DIR__"peak7",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-20);
	set("coor/y",60);
	set("coor/z",80);
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


