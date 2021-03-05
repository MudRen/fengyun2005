inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",6);

  set ("short", "摘星楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

    灵珠有泪自千行   等闲芳草斜阳

    离人过客暗凄凉   偷羡鸳鸯

LONG);
        set("exits", ([

  "down" : __DIR__"star"+(query("floor")-1),
  "up" : __DIR__"star"+(query("floor")+1), 
]));
        set("coor/x",-25);
        set("coor/y",-35);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
