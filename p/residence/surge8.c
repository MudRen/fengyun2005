inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",8);

  set ("short", "怒涛阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
  
    花无数  愁无数
    
    花好何须愁春去  戴花持酒祝东风
    
    千万莫匆匆
    
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