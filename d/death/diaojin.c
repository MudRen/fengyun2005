// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "吊筋狱");
        set("long", @LONG
这里是地狱的第一层，地狱共十八层，每三层关押同一类人犯，故实际关押六
种犯人。这第一种三层关押的是“寂寂寥寥，烦烦恼恼，尽是生前作下千般业，
死后通来受罪名”，在这吊筋狱中关押的皆是罪名较轻之人，受挑筋之苦，遍地
血腥，呻吟声此起彼伏，几个鬼卒来回逡巡，再往下便是幽枉狱。
LONG
        );
        set("exits", ([
		"up" : __DIR__"diyu",
		"down" : __DIR__"yiuwang",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-10);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
