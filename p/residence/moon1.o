inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",1);

  set ("short", "新月楼底层");
  set ("long", @LONG
  
    星沉月落夜闻香 素手出锋芒 前缘再续新曲 
    
    心有意 爱无伤 江湖远 碧空长 路茫茫 
    
    闲愁滋味 多感情怀 无恨思量 

LONG);
        set("exits", ([
  "up" : __DIR__"moon"+(query("floor")+1), 
  "southwest" : __DIR__"enterance",
]));
        set("coor/x",-15);
        set("coor/y",-35);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
