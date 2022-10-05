library(jsonlite)
library(httr)
library(dplyr)

#Read from FlightRadar24 JSON api 
dd <- fromJSON(paste0("https://data-live.flightradar24.com/zones/fcgi/feed.js?bounds=85.052,-81.094,-180,180&faa=1&satellite=1&mlat=1&flarm=1&adsb=1&gnd=1&air=1&vehicles=1&estimated=1&maxage=14400&gliders=1&stats=1"))

#Data cleaning
dd <- dd[-c(1,2,length(dd))]
df <- data.frame(matrix(unlist(dd), nrow=length(dd), byrow=T))
colnames(df) = c("id","lat","lng","hdg","alt","spd","x7","fcode","type","regis","time","departure","arrival","callsign","x15","x16","x17","x18","brand")

df %<>%
  filter(brand != "", callsign != "", lat != "",lng != "") %>% 
  select(-x7,-x15,-x16,-x18,-id)

#Export to csv file
write_csv2(df,"df.csv",col_names = TRUE)
