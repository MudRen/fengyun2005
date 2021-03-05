

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",5);

  set ("short", "藏剑阁"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG

人类最大的痛苦，也许就是永远无法控制自己的思想。
你若拼命想去回忆过去那些有趣的事情，但想到的偏总是那些辛酸和痛苦，
那时你心裡就会觉得好像有根针在刺着。

LONG);
        set("exits", ([
"517" : __DIR__"userroom/zza1582625830",
"516" : __DIR__"userroom/huluyb1553354271",
"515" : __DIR__"userroom/huluya1553354046",
"514" : __DIR__"userroom/hulujq1553344630",
"513" : __DIR__"userroom/hulubf1553344432",
"512" : __DIR__"userroom/huludwc1551694781",
"511" : __DIR__"userroom/hulufg1551684864",
"510" : __DIR__"userroom/hulugc1551679854",
"509" : __DIR__"userroom/hulugb1551677543",
"508" : __DIR__"userroom/huluga1551675796",
"507" : __DIR__"userroom/huluhsc1551675646",
"506" : __DIR__"userroom/huludzc1551675367",
"505" : __DIR__"userroom/hulukc1551428794",
"504" : __DIR__"userroom/hulukb1551428612",
"503" : __DIR__"userroom/huluka1551428163",
"502" : __DIR__"userroom/huluqc1551039223",
"501" : __DIR__"userroom/huluqb1551031119",
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
