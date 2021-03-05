inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",3);

  set ("short", "新月楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
  
    大梦初醒已千年   凌乱罗衫    料峭风寒
  
    放眼难觅旧衣冠   疑真疑幻    如梦如烟
  
    看朱成碧心迷乱   莫问生前    但惜因缘
  
    魂无归处为情牵   贪恋人间    不羡神仙
    
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
