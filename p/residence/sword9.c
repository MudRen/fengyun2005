

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",9);

  set ("short", "藏剑阁顶层");
  set ("long", @LONG

　　　　　　　　　　　　　永忆江湖归白发

　　　　　　　　欲回天地入扁舟

LONG);
        set("exits", ([
"913" : __DIR__"userroom/ffi1539966582",
"912" : __DIR__"userroom/ffj1538479118",
"908" : __DIR__"userroom/skysword1533474966",
"907" : __DIR__"userroom/glacier1533474336",
"906" : __DIR__"userroom/darkfire1533474124",
"903" : __DIR__"userroom/tinkling1533303875",
"902" : __DIR__"userroom/farseer1533295301",
"901" : __DIR__"userroom/psychic1533211503",
  "down" : __DIR__"sword"+(query("floor")-1),
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
