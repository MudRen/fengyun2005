inherit ROOM;
void create()
{
    set("short", "龙蛇广场");
    set("long", @LONG
此处本只是一个三教九流汇集的无名之地，经年累月来往的商贾多了，便也成
了集市；来来往往有大商高官，也有土匪强盗，更多的则是四海谋生的小商小贩，
后来不知谁称这里为龙蛇广场，叫的人多了，也就真的成了一个广场，在此设摊的
商贩集资在广场中央打了口水井，谓之龙井；一些贩茶的商人就随口就称自己卖的
叫龙井茶，久而久之，名闻遐迩的龙井茶由此得名。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"lssquare1",
	"south" : __DIR__"market",
	"north" : __DIR__"tuji",
	"east" : __DIR__"lssquare3",
      ]));
    set("objects", ([
	//        __DIR__"npc/wanfan" : 1,
      ]) );
    set("resource/water", 1);
    set("liquid",([
	"name":"龙井水",
	"container":"龙井"]));

    set("outdoors", "fengyun");
    set("coor/x",160);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
