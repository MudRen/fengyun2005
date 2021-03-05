inherit ROOM;
void create()
{
    set("short", "警世书局");
    set("long", @LONG
警世书局虽不是城中唯一的书局，却是城中卖书最多最快的地方。老板大有名
气，听说是当今皇太子的老师。凡是京都出的新书，都被快马送到这里，然后刻板
印刷。书局里不但有很多风骚文人喜欢的诗词，还卖一些粗浅的功夫书，供城中居
民练来强身健体。
LONG
    );
    set("exits", ([
	"east" : __DIR__"jidijie",
	"up":	__DIR__"jssju1",
      ]));
    set("objects", ([
	__DIR__"npc/bookseller": 1,
      ]) );

    set("coor/x",-40);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fynorth");
    setup();
    replace_program(ROOM);

}
