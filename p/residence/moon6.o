inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",6);

  set ("short", "新月楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
  
    平生书癖已均恙   解名缰   更逃羁网

    春近也   梅柳频看

    花间闲度   细雨流光

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