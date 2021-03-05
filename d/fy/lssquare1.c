inherit ROOM;
void create()
{
    set("short", "龙蛇广场");
    set("long", @LONG
这里原本是个很宽阔的树林，几年前突然一夜之间被夷为平地，然后同样突然
冒出来许多来自天南海北的商贩；有担着挑子卖着热乎乎的云吞的老伯，也有大婶
用苏白吆喝着：白糖方糕黄松糕，赤豆绿豆小甜糕。还有卖卤菜的、卖酒的、卖湖
北豆皮的、卖油炸窝面的、卖山东大馒头的、卖福州香饼的、卖岭南鱼蛋粉的、卖
烧鸭叉烧的、卖羊头肉、夹火烧的、卖鱿鱼羹的、卖豆腐脑的、卖北京豆汁的。。
似乎天下能想得出的商贩全都到了这里，简直比世上所有的庙会集都要热闹。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"southwest" : __DIR__"yulong2",
	"east" : __DIR__"lssquare2",
	"north" : __DIR__"zuisheng",
	"west" : __DIR__"seven",
      ]));
    set("objects", ([
	//        __DIR__"npc/wanfan" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",120);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}


