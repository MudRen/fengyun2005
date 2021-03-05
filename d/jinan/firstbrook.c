
inherit ROOM;

void create()
{
    set("short", "趵突泉");
	set("long", @LONG
趵突泉号称“天下第一泉”，与寻常泉水之柔弱截然不同。盛水季节，喷高一
尺以上，壮如三堆白雪，有诗赞云：三尺不消平地雪，四时尝吼半天雷。泉水似碧
玉一般温润晶莹，深处冉冉上浮的水泡，细似鱼眼，不绝如缕。临渊观泉，不觉心
平气和，油然而生一种浮生偷得半日闲的慵懒。泉边搭了间凉亭，一个黄衫少女正
烹茶小憩。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"street4",
]));
        set("objects", ([
        __DIR__"npc/songtian" : 1,
                        ]) );
        set("resource/water",1);
        set("liquid", ([
        "container":"趵突泉",
        "name":		"趵突泉水",
        	]));
        	
    set("outdoors", "jinan");
	set("coor/x",10);
	set("coor/y",40);
	set("coor/z",0);
	setup();
}

//void init()
//{
//    add_action("do_swim", "swim");
//}
//
//int do_swim(string arg)
//{
//   return 1;
//}
