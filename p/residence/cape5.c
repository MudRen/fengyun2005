inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",5);

  set ("short", "天涯海角楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

    帘外雨潺潺，春意阑珊。
    罗衾不耐五更寒。
    梦里不知身是客，一晌贪欢。

    独自莫凭栏，无限江山，
    别时容易见时难。
    流水落花春去也，天上人间。

    
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
