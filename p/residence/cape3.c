inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",3);

  set ("short", "天涯海角楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

    不寐倦长更，披衣出户行。
    
    月寒秋竹冷，风切夜窗声。


LONG);
        set("exits", ([

  "down" : __DIR__"cape"+(query("floor")-1),
  "up" : __DIR__"cape"+(query("floor")+1), 
]));
        set("coor/x",-25);
        set("coor/y",-45);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
