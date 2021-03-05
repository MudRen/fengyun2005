inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",2);

  set ("short", "怒涛阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
    
    此生自断天休问，独倚危楼。独倚危楼，不信人间别有愁。

    君来正是眠时节，君且归休。君且归休，说与西风一任秋。

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
