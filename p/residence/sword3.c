

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",3);

  set ("short", "藏剑阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

一个人就算久已习惯了孤独和寂寞，但有时还是会觉得很难忍受，
他忽然希望能有个人陪在他身边，不管什么样的人都好，越粗俗无知的人越好，
因为这种人不能接触到他内心深处的痛苦。

LONG);
        set("exits", ([
"317" : __DIR__"userroom/codya1552973130",
"316" : __DIR__"userroom/codyd1552970816",
"315" : __DIR__"userroom/hulucte1552755839",
"314" : __DIR__"userroom/huluctd1552755671",
"313" : __DIR__"userroom/huluctc1552755256",
"312" : __DIR__"userroom/huluctb1552661594",
"311" : __DIR__"userroom/hulucta1552508099",
"310" : __DIR__"userroom/huluhsd1552504557",
"309" : __DIR__"userroom/hulue1550431036",
"308" : __DIR__"userroom/hulud1550430685",
"307" : __DIR__"userroom/hulua1550243188",
"306" : __DIR__"userroom/hulub1550241064",
"305" : __DIR__"userroom/huluc1550167352",
"302" : __DIR__"userroom/hmt1512009990",
"301" : __DIR__"userroom/nxf1511099201",
  "down" : __DIR__"sword"+(query("floor")-1),
  "up" : __DIR__"sword"+(query("floor")+1), 
]));
  	set("coor/x",-30);
	set("coor/y",-40);
	set("coor/z",query("floor")*40);
	setup();
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
