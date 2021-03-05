// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// ban.c

#define BANNED_SITES "/adm/etc/banned_sites"
#define OK_SITES "/adm/etc/allowed_sites"

void load_sites();					// 读入	BANNED_SITES "/adm/etc/banned_sites"，ALLOWED_SITES "/adm/etc/allowed_sites"	
void add(string pattern);			// 在BANNED_SITE中写入一个ip
void delete(string pattern);		// 在BANNED_SITE中删除一个ip	
void add_allow(string pattern);		// 在ALLOWED_SITE中写入一个ip
void delete_allow(string pattern);
int  is_banned(string site);		// 校验输入ip合法性并login非法ip登陆信息
void print();						// debug打印BANNED_SITES
int save_site(string filename, string *data);

string *Sites;
string *OKSites;

void create()
{
	seteuid(getuid());
	load_sites();
}

void load_sites()
{
	string *tmp, file;
	int loop;

	Sites = ({});
	OKSites = ({});
	// reads in the list of the banned sites

	file = read_file(BANNED_SITES);
	if (!file) return;
	tmp = explode(file, "\n");
   	for(loop=0; loop<sizeof(tmp); loop++)
        	if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
           		continue;
        	else if (member_array(tmp[loop],Sites)==-1)
        		Sites += ({ tmp[loop] });
	save_site(BANNED_SITES, Sites);
	
    // reads in the list of the allowed sites
    file = read_file(OK_SITES);
    if (!file) return;

    tmp = explode(file, "\n");
    for(loop=0; loop<sizeof(tmp); loop++)
    	if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                       continue;
        else if (member_array(tmp[loop],OKSites) == -1)
        	OKSites += ({ tmp[loop] });
	save_site(OK_SITES, OKSites);
	
	return;
}

int is_banned(string site)
{
	string *line;
	int i;

	line = ({});
	line += ({site});

	for (i = 0; i < sizeof(OKSites); i++)
    	if (sizeof(regexp(line, OKSites[i])) == 1
    		&& line[0][0..2] == OKSites[i][0..2]
    	)
        return 0;

	for (i = 0; i < sizeof(Sites); i++)
		if (sizeof(regexp(line, Sites[i])) == 1
			&& line[0][0..2] == Sites[i][0..2]
		)
		{
			log_file("ATTEMPT_LOGIN",sprintf("SOMEONE  tried to login from banned site: %s\n",site));
			return 1;
		}
	return 0;
}


void print()
{
	int i;
	write("****	禁止登陆地址	****\n");
	for (i = 0; i < sizeof(Sites); i++)
		write(Sites[i] + "\n");
	
	write("****	允许登陆地址	****\n");	
	for (i = 0; i < sizeof(OKSites); i++)
		write(OKSites[i] + "\n");

}

int save_site(string filename, string *data) {
	int i/*, j*/, num;
	string comment;
//	string *field_2;
	
	num = sizeof(data);
	
	comment = "#" + filename + "\n";
	if( !write_file(filename, comment,1))
		return 0;
	
	for (i=0;i<num;i++) {
		if (!write_file(filename,(data[i]+"\n")))
				return 0;
	}
	
	write_file(filename,"\n");
	return 1;
}

void add(string site)
{
//	string filename;
	
	if (member_array(site,Sites)== -1)
	{
		Sites += ({site});
		save_site(BANNED_SITES, Sites);
		write("将"+site+"加入禁止登陆名单。\n");
	}else
		write("禁止登陆名单中已经有该地址了。\n");
}

void delete(string site)
{
//  int i;
	if (member_array(site,Sites)!= -1)
	{
		Sites -= ({site});
		save_site(BANNED_SITES, Sites);
		write("将"+site+"从禁止登陆名单中清除。\n");
	} else
		write("禁止登陆名单中没有该项地址。\n");    
}

void add_allow(string site)
{
	if (member_array(site,Sites)!= -1)
	{
		Sites -= ({site});
		save_site(BANNED_SITES, Sites);
		write("将"+site+"从禁止登陆名单中清除。\n");
	} 
	if (member_array(site,OKSites)== -1)
	{
		OKSites += ({site});
		save_site(OK_SITES, Sites);
		write("将"+site+"加入允许登陆名单。\n");
	}else
		write("允许登陆名单中已经有该地址了。\n");

}

void delete_allow(string site){
	if (member_array(site,OKSites)!= -1) 
	{
		OKSites -= ({site});
		save_site(OK_SITES, OKSites);
		write("将"+site+"从允许登陆名单中清除。\n");
	} else
		write("允许登陆名单中没有该项地址。\n");
}


/*
void dynamic_add(string site)
{
	if(stringp(site))
	Sites += ({ site });
        write("Ｏ．Ｋ．\n");
}

void dynamic_remove(string site)
{
	Sites -= ({site});
        write("Ｏ．Ｋ．\n");
}
*/