// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "剥皮狱");
        set("long", @LONG
几只大钩子悬于半空，上悬数人，几个牛头，马面以极为熟练的手法在人犯头
顶开口，然后灌入水银，旋即剥下一张完整的人皮，令人做呕，地府之酷刑，一至
于斯，一牛头鬼似乎看穿了你的心思，淡然说道“十恶不赦之徒，非此不能降其心
啊，地府之中，虽酷但自有公道”。话虽如此，你还是忍耐不住，向下面的磨捱狱
走去。
LONG
        );
        set("exits", ([
		"up" : __DIR__"bashe",
		"down" : __DIR__"moai",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-60);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
