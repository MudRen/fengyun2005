inherit ROOM;
void create()
{
        set("short", "探花诗台");
        set("long", @LONG
风云中的老老少少大都有吟诗对词的雅好。只要稍有灵感，就会带着笔墨到这里来
酝酿，等到灵光乍现那霎那，奋笔急书，以求千古名句。诗台正中朱笔入木狂草：
[33m
                       今日有酒今朝醉，
                       哪管它日剑割头！
                                       阿铁狂舞于酒后失意时。

[37m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wcloud1",
]));
        set("objects", ([
        __DIR__"npc/yaren" : 1,
	__DIR__"npc/prince" : 1,
                        ]) );
        set("coor/x",-10);
        set("coor/y",1);
        set("coor/z",-300);
        setup();
        call_other( "/obj/board/poem_b", "???" );
}
