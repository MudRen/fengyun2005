//Sinny@fengyun 2003
//All Rights Reserved

#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", GRN"绿竹斋"NOR);
    set("long", @LONG
绿竹斋并不十分宽敞，但却也不显得丝毫局促，斋中一方竹几，三两张绿竹椅，
便只有门前翠绿的竹帘随风哗哗吹动。正堂上一幅工笔翠竹婉约细致，那是小师妹
花茵送给此斋昔日的主人琴心，一旁便是剑胆狂放不羁的题字：瞻彼淇奥，绿竹猗
猗。有匪君子，如切如磋，如琢如磨。瞻彼淇奥，绿竹青青。有匪君子，充耳琇莹。
会弁如星。语出诗经国风，倒正切合了其时四人的微妙心境。
LONG
    );
    set("exits",
      ([
	"west" : __DIR__"skystreet2",
      ]));
    set("objects",
      ([
	__DIR__"npc/yihai" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",10);
    set("coor/y",-180);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
