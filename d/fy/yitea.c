inherit ROOM;
void create()
{
    set("short", "眉峰聚");
    set("long", @LONG
卖的是各地的名茶，冲茶的水是从枫叶泉专程汲来，冲茶的壶是名贵的紫砂壶，
冲茶的方法也是最讲究的：每壶茶的第一杯是用来养壶的。所以这里冲出的茶都有
一种纯厚的香气。而原本的一品居已被金钱帮购置下，扩建为“眉峰聚”，总是笑
容可掬的茶博士也回江南养老去了，而打理此处的据说是闻名天下的茶道高手。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"yundoor",
	"up" :   __DIR__"yitea2",
      ]));
    set("objects", ([
	__DIR__"npc/teawaiter" : 1,
      ]) );

    set("coor/x",20);
    set("coor/y",-40);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}
