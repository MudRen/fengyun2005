// XXder@fy3
inherit ROOM;
void create()
{
        set("short", "伙房");
        set("long", @LONG
进门来便有股大葱的香气扑面而来，几个丫环正在忙碌着，台子上红红绿绿摆
了十几个碟子，因为地处鲁南，菜色受了孔府菜的影响，所以也颇精致。台面上的
辣子鸡丁、夫妻肺片，吸引了你的视线，你没想到在这里还有人做出道地的四川菜。
不过主食还是大葱蘸酱和薄饼。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"southting",
]));

	set("coor/x",-40);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
