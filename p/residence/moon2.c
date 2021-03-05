inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",2);

  set ("short", "新月楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
    
    身世飘零叹孤独 回顾盼相扶 情天不老 雷霆易逝 雨过云舒

    相思不忍轻离别 携手更如初 风急波涌 扁舟不系 终恋江湖

LONG);
        set("exits", ([

  "down" : __DIR__"moon"+(query("floor")-1),
  "up" : __DIR__"moon"+(query("floor")+1), 
]));
        set("coor/x",-15);
        set("coor/y",-35);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
