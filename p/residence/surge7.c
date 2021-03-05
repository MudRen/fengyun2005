inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",7);

  set ("short", "怒涛阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
  
    欲上高楼去避愁，愁还随我上高楼。经行几处江山改，多少亲朋尽白头！

    归休去，去归休，不成人总要封侯。浮云出处元无定，得似浮云也自由。
    
LONG);
        set("exits", ([

  "down" : __DIR__"surge"+(query("floor")-1),
  "up" : __DIR__"surge"+(query("floor")+1), 
]));
        set("coor/x",-15);
        set("coor/y",-45);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/