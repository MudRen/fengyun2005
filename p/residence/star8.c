inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",8);

  set ("short", "摘星楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

    锦瑟年华谁与度
    
    莫问情归处  只影向斜阳
    
    剑吼西风  欲把春留驻
    
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
