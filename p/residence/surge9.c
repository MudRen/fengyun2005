inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",9);

  set ("short", "怒涛阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
    
    少年不识愁滋味，爱上层楼。爱上层楼，为赋新词强说愁。

    而今识尽愁滋味，欲说还休。欲说还休，却道天凉好个秋！
    
LONG);
        set("exits", ([
  "down" : __DIR__"surge"+(query("floor")-1),
]));
        set("coor/x",-15);
        set("coor/y",-45);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/