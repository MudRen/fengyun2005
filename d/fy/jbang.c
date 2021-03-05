inherit ROOM;
void create()
{
    set("short", "帮主堂");
    set("long", @LONG
这么大的屋子，只有一个窗户，很小的窗户，离地很高。窗户是关着的，看不
到外面的景色。门也很小，肩稍宽的人，就只能侧身而入。墙上漆着白色的漆，漆
得很厚，仿佛不愿人看出这墙是石壁，是土，还是铜铁所筑。角落里有两张床，木
床。床上的被褥很干净，却很简朴。除此之外，屋里只有一张很大的桌子。桌子上
堆埋了各式各样的账册和卷宗。没有椅子，连一张椅子都没有。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"jhuang1",
      ]));
    set("objects", ([
	__DIR__"npc/jinwuming" : 1,
	__DIR__"npc/shangguan" : 1,
      ]) );
    set("valid_startroom", 1);
    set("coor/x",-180);
    set("coor/y",40);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}
