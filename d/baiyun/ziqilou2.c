//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "紫气东来二楼");
    set("long", @LONG
相比于一楼的雍容华丽，金壁辉煌，二楼却格外的清淡素雅，四面都是敞亮的窗
户，楼内整整齐齐放了四张檀木香几，东侧摆的是一个瑶琴，南首放了一盘玉雕棋秤，
西面挂了一幅水墨淋漓的狂草，而北面搁着一卷画轴。
LONG
    );
    set("exits",
      ([
	"down" : __DIR__"ziqilou",
      ]));
    set("objects",
      ([
	//       __DIR__"npc/yexingshi" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",20);
    set("coor/y",-130);
    set("coor/z",40);
    setup();
    replace_program(ROOM);
}
