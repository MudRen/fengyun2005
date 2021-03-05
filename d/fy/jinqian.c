inherit ROOM;
void create()
{
    set("short", "金钱帮大院");
    set("long", @LONG
大院里冷冷清清，静的出奇。院中的老树在地上拖出长长的影子。偶尔几声鸟
叫，打破死沉沉的寂静。微风吹过，树叶舞动，发出“沙沙”的声音。黄沙的地面
铺满枯黄的落叶。几条黄色的人影在阴暗的角落里忽隐忽现。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"jindoor",
	"west" : __DIR__"jting",
      ]));
    set("outdoors", "fengyun");
    set("coor/x",-160);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}
