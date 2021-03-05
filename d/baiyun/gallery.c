//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "白云画院");
    set("long", @LONG
白云岛历来推崇通晓琴棋书画的文人雅客。即使在白云五仙中，虽然以花茵入门
最晚，武学修为也甚浅，但却最得白云仙和其他四人疼爱，一方面固是由于花茵可爱
娇小，但另一方面，也是因为花茵的画道修为高出众人许多，白云城主叶孤城后来更
是专辟了一地作为花茵传授白云弟子的场所，但花茵嫌此地太俗，更因和叶孤城不睦，
反而搬到城外岛上小栖。此处也暂由叶孤城诚邀的南派大家僧巨然主持。
LONG
    );
    set("exits",
      ([
	"east" : __DIR__"skystreet2",
      ]));
    set("objects",
      ([        __DIR__"npc/juran" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",-10);
    set("coor/y",-180);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
