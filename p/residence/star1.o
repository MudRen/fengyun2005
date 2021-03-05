inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",1);

  set ("short", "摘星阁底层");
  set ("long", @LONG

    千金难求珍宝 家和易得欢笑 人生自是有情痴 愿作双飞鸟

    情两难分付 是一丝烦恼 蓦然回首神仙地 还是人间好


LONG);
        set("exits", ([

  "up" : __DIR__"star"+(query("floor")+1), 
  "southeast" : __DIR__"enterance",
]));
        set("coor/x",-25);
        set("coor/y",-35);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
