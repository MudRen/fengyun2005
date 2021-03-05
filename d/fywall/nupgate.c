inherit ROOM;
void create()
{
    set("short", "北城门楼");
    set("long", @LONG
楼呈方形，往下望是川流不息的人群，阳光下，流动的人群象微风中的彩带,
南方是风云城的中心，就是在这里也可以依稀的看到风云广场中心的纹龙柱。城中
的房屋连绵不断，索碎的小路象细小的银蛇，蜿蜒盘旋在灰色的房屋之间.
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"down" : AREA_FY"ngate",
	"west" : __DIR__"nwall1",
	"east" : __DIR__"nwall10",
      ]));
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",300);
    set("coor/z",30);
    set("coor/x",0);

    set("objects", ([
	__DIR__"npc/j" : 1,
      ]) );

    set("coor/y",180);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
