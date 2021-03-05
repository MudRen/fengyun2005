inherit ROOM;
void create()
{
    set("short", "镇风兵器铺");
    set("long", @LONG
当今武林奇侠辈出，武林好汉空前众多，这里的生意也因此好得不得了。此处
的老板就是这四个甲子名气最响亮的金狮总镖头。这里的大掌柜则是当年大镖头的
儿子。这里的兵器应有尽有，绝对不会有买不到的。
LONG
    );
    set("exits", ([
	"south" : __DIR__"ecloud3",
      ]));
    set("objects", ([
	__DIR__"npc/weaponer": 1,
	__DIR__"npc/biaoshi_wang" : 1,
      ]) );
    set("coor/x",160);
    set("coor/y",20);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);

}
