// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "幽枉狱");
        set("long", @LONG
这里不见血腥，也不闻呼声，这里的犯人全部被单独关押，寂寥无声，所有人
之间无法交谈，一关就是数十年，几个鬼卒皆是天生哑人，亦不发语，所以一片寂
静尤为可怕，较之吊筋狱更让人恐惧。下一层的火坑狱会怎样？
LONG
        );
        set("exits", ([
		"up" : __DIR__"diaojin",
		"down" : __DIR__"huokeng",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-20);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
