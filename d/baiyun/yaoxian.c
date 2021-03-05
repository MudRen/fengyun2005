//Sinny@fengyun 2003
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIR"摇仙佩"NOR);
    set("long", @LONG
飞琼伴侣，偶别珠宫，未返神仙行缀。取次梳妆，寻常言语，有得几多姝丽。
拟把名花比。恐旁人笑我，谈何容易。细思算，奇葩艳卉，惟是深红浅白而已。争
如这多情，占得人间，千娇百媚。须信画堂绣阁，皓月清风，忍把光阴轻弃。自古
及今，佳人才子，少得当年双美。且恁相偎倚。未消得，怜我多才多艺。愿奶奶、
兰人蕙性，枕前言下，表余深意。为盟誓。今生断不孤鸳被。 
LONG
    );
    set("exits",
      ([
	"up" : __DIR__"mixian",
	"down" : __DIR__"wangxian",
      ]));
    set("objects",
      ([
	__DIR__"npc/yaoxian" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",30);
    set("coor/y",-160);
    set("coor/z",40);
    setup();
    replace_program(ROOM);
}
