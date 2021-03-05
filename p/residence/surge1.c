inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",1);

  set ("short", "怒涛阁底层");
  set ("long", @LONG

    萱花别样红  亭亭发几丛  凝露仰宿雨  窈窕舞熏风
    
    宜男不忍佩  仙人岂相通  解语朝暮伴  忘忧了残生

LONG);
        set("exits", ([

  "northwest" : __DIR__"enterance",
  "up" : __DIR__"surge"+(query("floor")+1), 
]));
        set("coor/x",-15);
        set("coor/y",-45);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
