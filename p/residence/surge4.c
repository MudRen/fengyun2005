inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",4);

  set ("short", "怒涛阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
  
    醉里且贪欢笑，要愁那得功夫。近来始觉古人书，信着全无是处。
    
    昨夜松边醉倒，问松我醉如何？只疑松动要来扶，以手推松曰去！
    
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
