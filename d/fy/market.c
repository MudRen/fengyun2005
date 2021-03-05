// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
void create()
{
    set("short", "龙蛇集");
    set("long", @LONG
这里是风云城里最大的南北货集市，不少名流商贾每天流连在这里。除了常见
的生活用品和一些土特产品以外，从各地来的奇珍异宝都能在这里得见，有名满天
下的南珠，也有产自西域的汗血宝马，更有来自苏杭一带的丝绸刺绣及胭脂水粉，
还有不远千里、远渡重洋的商船队带来异邦的各种稀奇的玩意。除了众多商贾云集
此处，一些黑道帮派也通过在这里的贸易，进行销赃洗钱。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"lssquare2",
      ]));
    set("objects", ([
	__DIR__"npc/mai" : 1,
	__DIR__"npc/zhen" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",160);
    set("coor/y",60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
