// A unified WHO, WHO -i
#include <net/macros.h>
#include <ansi.h>
#include <net/dns.h>
#include <net/daemons.h>
string *REMOTE_IDS=({});
string *REMOTE_NAMES=({});
void create()
{
        seteuid(getuid());
	call_out("query_ids",3*60);

}

void query_ids()
{
	mapping mud_list;
	mixed *muds;
//	object me;
	int i;
 if(find_object(DNS_MASTER))
 {
  mud_list=(mapping)DNS_MASTER->query_muds();
  muds = keys(mud_list);
  for(i=0;i<sizeof(muds);i++)
        if(( muds[i] != lower_case(INTERMUD_MUD_NAME)))
        {
                RWHO_Q->send_rwho_q(muds[i],this_object(),1);
                RWHO_Q->send_rwho_q(muds[i],this_object(),0);
        }
 }
 call_out("query_remotes",1*60);
}

string local_whos(string arg)
{
// arg can be -i id onnly, -n name only -l long 

	string str = "◎ " + MUD_NAME + "\n";
	object *list;
	int ppl_cnt,j;
	list = sort_array(users(),"sort_user",this_object());
	j = sizeof(list);
	ppl_cnt = 0;
	str += "—————————————————————————————————————\n";
	while( j--)
	{
	if( !environment(list[j]) ) continue;
	switch(arg) {
	case "-i" :
        str = sprintf("%s%-15s%s",
                str,
                capitalize(list[j]->query("id")),
                (ppl_cnt%5==4? "\n": "")
        );
        ppl_cnt++;
		break;
	case "-n" :
        str = sprintf("%s%-15s%s",
                str,
                list[j]->name(1),
                (ppl_cnt%5==4? "\n": "")
        );
        ppl_cnt++;
                break;
	case "-l" :
	str = sprintf("%s%s",
                str,
                list[j]->short(1)+"\n");
		break;
        case "-w" :
		if(wizardp(list[j]) ){
        str = sprintf("%s%s",
                str,
                list[j]->short(1)+"\n");
					}
                break;
	default :
        str = sprintf("%s%-15s%s",
                str,
                list[j]->name(1),
                (ppl_cnt%5==4? "\n": "")
        );
        ppl_cnt++;
		    }
	}	
        switch(arg) {
        case "-n" :
		for(j=0;j<sizeof(REMOTE_NAMES);j++)
		{
		str = sprintf("%s%-15s%s",
                str,
                REMOTE_NAMES[j],
                (ppl_cnt%5==4? "\n": "")
		        );
        ppl_cnt++;
		}
		break;
	case "-i" :
                for(j=0;j<sizeof(REMOTE_IDS);j++)
                {
                str = sprintf("%s%-15s%s",
                str,
                REMOTE_IDS[j],
                (ppl_cnt%5==4? "\n": "")
                        );
        ppl_cnt++;
                }
		break;
	case "-l" : break;
	case "-w" : break;
	default :
                for(j=0;j<sizeof(REMOTE_NAMES);j++)
                {
                str = sprintf("%s%-15s%s",
                str,
                REMOTE_NAMES[j],
                (ppl_cnt%5==4? "\n": "")
                        );
        ppl_cnt++;
                }
	}
        if(arg!="-l" && arg!="-w") str+="\n";
        str +="—————————————————————————————————————\n";
	str = sprintf("%s共有%s位人士（本地%s位）正在游戏中。\n", str, 
	chinese_number(sizeof(list)+sizeof(REMOTE_NAMES)), chinese_number(sizeof(list)));
	return str;
}


string for_remote_who(string arg)
{
// arg can be -i id onnly, -n name only 
	string str="";
	object *list;
	int /*ppl_cnt,*/j;
	list = users();
	j = sizeof(list);
	while( j--)
	{
	if( !environment(list[j]) ) continue;
	switch(arg) {
	case "-i" :
        str += sprintf("%s ",
                capitalize(list[j]->query("id"))
        );
		break;
	case "-n" :
        str += sprintf("%s ",
                list[j]->name(1)
        );
                break;
	default :
        str += sprintf("%s ",
                capitalize(list[j]->query("id"))
        );
		    }
	}	
	return str;
}

void query_remotes()
{
 int i/*,j*/;
 string *dir;
 string file;
 string site;
 dir = get_dir(REMOTE_DIR);
// clear out the array first
 REMOTE_IDS=({});
 REMOTE_NAMES=({});
 for(i=0;i<sizeof(dir);i++)
 {
  reset_eval_cost();
  if(strsrch(dir[i], "name") != -1)
  {
// this is a name file
  if(file_size(REMOTE_DIR+dir[i]) <= 0) continue;
  file = read_file(REMOTE_DIR+dir[i]);
  if(!stringp(file)) continue;
  file = replace_string(file,"\n","");
  REMOTE_NAMES += explode(file, " ");
  }
  if(strsrch(dir[i], "id") != -1)
  {
// this is a id file
  sscanf(dir[i],"id%s",site);
  site =lower_case(site);
  if(file_size(REMOTE_DIR+dir[i]) <= 0) continue;
  file = read_file(REMOTE_DIR+dir[i]);
  if(!stringp(file)) continue;
  file = replace_string(file,"\n","");
  file = replace_string(file," ",site+" ");
  REMOTE_IDS += explode(file, " ");
  }
 }
call_out("query_ids",15*60); 
}


int query_num()
{
	return sizeof(users())+sizeof(REMOTE_NAMES);
}

int sort_user(object ob1, object ob2)
{
        if( wizardp(ob1) && !wizardp(ob2) ) return -1;

        if( wizardp(ob2) && !wizardp(ob1) ) return 1;


	return strcmp(ob1->short(1)+" ",ob2->short(1)+ " ");
}