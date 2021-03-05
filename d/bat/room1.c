inherit ROOM;
void create()
{
        set("short", "销魂窝");
        set("long", @LONG
屋子里的香气更浓，浓得几乎可以令人溶化。 陌生的地方，陌生的女人，黑暗…… 
世上又有哪个男人能抵抗这种可怕的诱惑......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zoulang1",
]));
        set("objects", ([
        __DIR__"npc/woman" : 1,
                        ]) );
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
