inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",8);

  set ("short", "天涯海角楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

    转烛飘蓬一梦归，
    欲寻陈迹怅人非，
    天教心愿与身违。

    待月池台空逝水，
    荫花楼阁谩斜晖，
    登临不惜更沾衣。

    
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
