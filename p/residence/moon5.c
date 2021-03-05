inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",5);

  set ("short", "新月楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
  
    碧水连天静无浪   转东风   滟纹微张

    个中趣   莫遣人知   年年日日   兰舟共上
    
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
