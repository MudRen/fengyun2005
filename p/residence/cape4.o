inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",4);

  set ("short", "天涯海角楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
    
    林花谢了春红，
    太匆匆，
    无奈朝来寒雨晚来风。

    胭脂泪，相留醉，
    几时重。
    自是人生长恨水长东。


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
