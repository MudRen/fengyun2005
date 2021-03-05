inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",6);

  set ("short", "怒涛阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
  
    凤额绣帘高卷，兽环朱户频摇。两竿红日上花棚。春睡厌厌难觉。

    好梦狂随飞絮，闲愁浓，胜香醪。不成雨暮与云朝。又是韶光过了。


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