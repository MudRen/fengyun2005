inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",7);

  set ("short", "新月楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
  
    情眷恋   古往今来相看   几度流光人更远   伤离方寸乱
        
    回梦空传幽怨   依旧尘缘未断
        
    碧落黄泉寻觅遍   愁来天不管
    
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